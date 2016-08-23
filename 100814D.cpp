#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<pair<ll, int> > > g;
vector<ll> leaves, ans;
ll t[100005];

int upperbound(ll s)
{
	int b = 0;
	int e = ans.size() - 1;
	if (ans[b] > s) return 0;
	if (ans[b] == s) return 1;
	if (ans[e] <= s) return e + 1;
	
	int mid;
	
	while (b <= e)
	{
		mid = (b + e) >> 1;
		
		if (ans[mid] == s)
		{
			while (ans[mid] == s)
				++mid;
				
			return mid;
		}
		if (ans[mid] < s && s < ans[mid + 1]) return mid + 1;
		
		if (ans[mid] > s) e = mid;
		else b = mid;
	}
	return -1;
}
int main()
{
	int cases;
	int n;
	
	int v;
	ll w;
	ll q;
	ll x;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
		
	cin >> cases;
	while (cases--)
	{
		cin >> n;
		g.assign(n, vector<pair<ll, int> > ());
		for (int i = 1 ; i < n ; ++i)
		{
			cin >> v >> w;
			--v;
			g[v].push_back(make_pair(w, i));
		}
		leaves.clear();
		for (int i = 0 ; i < n ; ++i)
		{
			if (!g[i].size())
				leaves.push_back(i);
			else sort(g[i].begin(), g[i].end()); //ordena so pra ficar mais facil de pegar a aresta de menor custo
		}
		
		memset(t, 0, sizeof t);
		t[0] = 0;
		for (int i = 0 ; i < n; ++i)
		{
			if (g[i].size())
			{
				ll shortest = g[i][0].first;
				for (int j = 0 ; j < g[i].size(); ++j)
					t[g[i][j].second] = t[i] + shortest + (g[i][j].first - shortest) * 2; //o tempo pra derreter a aresta (i, g[i][j].second) é o tempo de derreter até o vertice i + o tempo que leva pra aresta de menor custo derreter + o dobro do que restar ja que a taxa cai pra 0.5 segundos
			}
		}
		
		ans.assign(leaves.size(), 0);
		for (int i = 0; i < leaves.size(); ++i)
			ans[i] = t[leaves[i]]; //coloca os tempos em que terá uma folha derretida

		sort(ans.begin(), ans.end());
		cin >> q;

		while (q--)
		{
			cin >> x;
			if (!x) cout << 0 << '\n';
			else cout << upperbound(x) << '\n';
		}
	}
}
