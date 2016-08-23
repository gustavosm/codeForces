#include <bits/stdc++.h>

#define MAXN 200005
#define LOGTWON 18
#define cl(x) ((x) << 1)
#define cr(x) (((x) << 1) + 1)
#define LINF 4000000000000000000LL
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;


inline ll mul(ll left, ll right)
{
	ll ret;
	
	if (right < LINF / left) ret = right * left;
	else ret = LINF;
	return ret;
}
class RMQ{
private:
	int SpT[2 * MAXN][2 * LOGTWON];
	int _A[2 * MAXN];
public :
	void build ( int n , int A[] ) {
		for ( int i = 0 ; i < n ; ++i) { 
			_A[i] = A[i] ; 
			SpT[i][0] = i ; 
		}
		for (int j = 1; (1 << j) <= n; ++j)
		{
			for (int i = 0 ; i + (1 << j) - 1 < n; ++i)
			{
				if (_A[SpT[i][j - 1]] < _A[SpT[i + (1 << (j - 1))][j - 1]])
					SpT[i][j] = SpT[i][j - 1];
				else SpT[i][j] = SpT[i + (1 << (j - 1))][j - 1];
			}
		}
	}
	int query(int i , int j){
		int k = (int)floor(log((double)j - i + 1) / log(2.0));
		if (_A[SpT[i][k]] <= _A[SpT[j - (1 << k) + 1][k]])
			return SpT[i][k];
		else return SpT[j - (1 << k) + 1][k];
	}
};
class LCA{
private:
	RMQ rmq;
	int L[2 * MAXN], E[2 * MAXN], H[MAXN], idx;
	
	void dfs(int cur, int depth, vvi &children)
	{
		H[cur] = idx;
		E[idx] = cur;
		L[idx++] = depth;
		for (int i = 0 ; i < (int)children[cur].size(); ++i)
		{
			dfs(children[cur][i], depth + 1, children);
			E[idx] = cur;
			L[idx++] = depth;
		}
	}
public:
	void build(vvi &children)
	{
		idx = 0;
		memset(H, -1, sizeof H);
		dfs(0, 0, children);
		rmq.build(idx, L);
	}
	int query(int u, int v)
	{
		if (H[v] < H[u]) swap(u, v);
		return E[rmq.query(H[u], H[v])];
	}
};

class HLD{
private:
	LCA lca;
	int chainNo, chainPtr, n;
	int chainHead[MAXN], chainPos[MAXN], chainInd[MAXN], tree_sz[MAXN], parent[MAXN];
	ll st[4 * MAXN], arrBase[MAXN];
	
	void build_tree(int x, int l, int r)
	{
		if (l == r) st[x] = arrBase[l];
		else
		{
			build_tree(cl(x), l, (l + r) / 2);
			build_tree(cr(x), (l + r) / 2 + 1, r);
			
			ll left = st[cl(x)];
			ll right = st[cr(x)];
			
			st[x] = mul(left, right);
		}
	}
	
	ll query_tree(int x, int l, int r, int i, int j)
	{
		if (j < l || i > r) return 1LL;
		
		if (l >= i && r <= j) return st[x];
		
		ll left = query_tree(cl(x), l, (l + r) / 2, i , j);
		ll right = query_tree(cr(x), (l + r) / 2 + 1, r, i , j);
		
		return mul(left, right);
	}
	
	void update_tree(int x, int l, int r, int ponto, ll val)
	{
		if (l == r && r == ponto)
			st[x] = val;
		else if (ponto < l || ponto > r) return;
		else
		{
			update_tree(cl(x), l, (l + r) / 2, ponto, val);
			update_tree(cr(x), (l + r) / 2 + 1 , r, ponto, val);
			
			ll left = st[cl(x)];
			ll right = st[cr(x)];
			
			st[x] = mul(left, right);
		}
	}
	ll query_up(int u, int v)
	{
		if (u == v) return 1;
		ll qry;
		int uchain, vchain = chainInd[v];
		ll ans = 1;
		while (1)
		{
			uchain = chainInd[u];
			if (uchain == vchain)
			{
				if (u == v) break;
				qry = query_tree(1, 0, n - 1, chainPos[v] + 1, chainPos[u]);
				ans = mul(ans, qry);
				break;
			}
			qry = query_tree(1, 0, n - 1, chainPos[chainHead[uchain]], chainPos[u]);
			ans = mul(ans, qry);
			u = parent[chainHead[uchain]];
		}
		return ans;
	}
	
	int dfscnt(int u, vvi &children)
	{
		int v;
		tree_sz[u] = 1;
		
		for (int i = 0 ; i < (int)children[u].size(); ++i)
		{
			v = children[u][i];
			parent[v] = u;
			tree_sz[u] += dfscnt(v, children);
		}
	
		return tree_sz[u];
	}
	
	void hld(int u, ll cst, vvi &children, vvi &costs){
		arrBase[chainPtr] = cst;
		if (chainHead[chainNo] == -1) chainHead[chainNo] = u;
		
		chainInd[u] = chainNo; chainPos[u] = chainPtr++;
		
		ll ind = n, nc, v;
		
		for (int i = 0; i < (int)children[u].size(); ++i)
		{
			v = children[u][i];
			if (tree_sz[v] > tree_sz[ind]){
				ind = v;
				nc = costs[u][i];
			}
		}
		if (ind == n) return;
		
		hld(ind, nc, children, costs);
		for (int i = 0 ; i < (int)children[u].size(); ++i)
		{
			v = children[u][i];
			if (v != ind)
			{
				++chainNo;
				hld(v, costs[u][i], children, costs);
			}
		}
	}
	
public:
	HLD(){
		lca = LCA();
	}
	
	void build(vvi &children, vvi &costs){
		memset(tree_sz, -1, sizeof tree_sz);
		
		n = children.size();
		dfscnt(0, children);
		
		chainNo = 0;
		memset(chainHead, -1, sizeof chainHead);
		
		chainPtr = 0;
		
		hld(0, 1, children, costs);
		
		lca.build(children);
		build_tree(1, 0, n - 1);
	}
	ll query(int u, int v){
	
		int l = lca.query(u, v);
		ll ans1 = query_up(u, l), ans2 = query_up(v, l);
		
		//cout << "LCA entre " << u << ' ' << v << " == " << l << " prod = " << ans1 << ' ' << ans2 << '\n';
		return mul(ans1, ans2);
	}
	
	void update(int u1, int u2, ll v)
	{
		int u;
		if (parent[u1] == u2) u = u1;
		else u = u2;
		
		update_tree(1, 0, n - 1, chainPos[u], v);
	}
};

HLD hld;

vector<pair<int, int> > edges;
vvi g;
vvi custo;
vvi mst;

void dfs(int u, int pai)
{	
	for (int i = 0 ; i < g[u].size(); ++i)
	{
		if (g[u][i] != pai)
		{
			mst[u].push_back(g[u][i]);
			dfs(g[u][i], u);
		}
		else custo[u].erase(custo[u].begin() + i);
	}
}

int main()
{
	int n, m;
	ll u, v, w;
	int op;
	
	
	ios_base :: sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	
	mst.assign(n, vi());
	g.assign(n, vi());
	custo.assign(n, vi());
	for (int i = 0 ; i < n - 1 ; ++i)
	{
		cin >> u >> v >> w;
		--u; --v;
		
		g[u].push_back(v);
		g[v].push_back(u);
		
		edges.push_back(make_pair(u, v));
		
		custo[u].push_back(w);
		custo[v].push_back(w);
	}
	
	dfs(0, -1);
	hld.build(mst, custo);
	
	for (int i = 0 ; i < m; ++i)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> u >> v >> w;
			--u; --v;
			ll prod = hld.query(u, v);
			//cout << "prod deu " << prod << '\n';
			cout << (w / prod) << '\n';
		}
		else
		{
			cin >> u >> v;
			
			--u;
			
			hld.update(edges[u].first, edges[u].second, v);
		}
	}
}
