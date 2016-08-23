#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

map<pair<ll, ll>, ll> m;
map<ll, ll> comp;

vector<ll> pset;
vector<pair<ll, pair<ll, ll> > > edges;
vector<vector<ll> > g;
int vis[400005];
vector<ll> ans;
int componente;

void init(int n)
{
	pset.assign(n, 0);
	for (int i = 0 ; i < n; ++i) pset[i] = i;
}

int find(int i)
{
	return (pset[i] == i ? i : pset[i] = find(pset[i]));
}

int same(int i, int j)
{
	return find(i) == find(j);
}

void une(int i, int j)
{
	pset[find(i)] = find(j);
}

void dfs(int n)
{
	comp[n] = componente;
	vis[n] = 1;
	
	for (int i = 0 ; i < (int)g[n].size(); ++i)
	{
		if (!vis[g[n][i]])
			dfs(g[n][i]);
	}
}
int main()
{
	int n;
	ll x1, y1, x2, y2;
	
	cin >> n;
	
	int pos = 0;
	g.assign(2 * n, vector<ll> ());
	ans.assign(2 * n, 0);
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		pair<ll, ll> u = make_pair(x1, y1);
		pair<ll, ll> v = make_pair(x2, y2);
		int u1, v1;
		if (!m.count(u)) u1 = pos, m[u] = pos++;
		else u1 = m[u];
		
		if (!m.count(v))  v1 = pos, m[v] = pos++;
		else v1 = m[v];

		g[u1].push_back(v1);
		g[v1].push_back(u1);
		
		edges.push_back(make_pair(abs(x1 - x2) + abs(y1 - y2), make_pair(u1, v1)));		
	}
	
	memset(vis, 0, sizeof vis);
	componente = 0;
	for (int i = 0 ; i < pos; ++i)
	{
		if (!vis[i])
		{
			dfs(i);
			++componente;
		}
	}
	
	sort(edges.rbegin(), edges.rend());
	int m = (int)edges.size();
	init(pos);
	
	for (int i = 0 ; i < m ; ++i)
	{
		pair<ll, pair<ll, ll> > &p = edges[i];
		pair<ll, ll> &u = p.second;
		if (!same(u.first, u.second))
		{
			une(u.first, u.second);
			ans[comp[u.first]] += p.first;
		}
	}
	cout << *max_element(ans.begin(), ans.end()) << '\n';
	
	
}
