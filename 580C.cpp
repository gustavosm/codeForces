#include <bits/stdc++.h>

#define INF 12381238
using namespace std;

typedef long long ll;

ll n;
vector<vector<ll> > v;
vector<vector<ll> > child;
vector<int> visited;
ll cats[100006];
ll dist[100006];
ll m;
ll ans;


void dfs(int w)
{
	visited[w] = 1;
	
	for (int i = 0 ; i < v[w].size(); ++i)
	{
		if (!visited[v[w][i]])
		{
			child[w].push_back(v[w][i]);
			dfs(v[w][i]);
		}
	}
}
void dfs2(int w, int cat)
{
	visited[w] = 1;
	if (child[w].size() == 0)
		++ans;
		
	for (int i = 0 ; i < child[w].size(); ++i)
	{
		if (!visited[child[w][i]])
		{
			if (!cats[child[w][i]]) dfs2(child[w][i], 0);
			else
			{
				if (cat + 1 <= m) dfs2(child[w][i], cat + 1);
			}
		}
	}
}

int main()
{
	while (cin >> n >> m)
	{
	
		ll x, y;
	
		v.assign(n, vector<ll> ());
		child.assign(n, vector<ll> ());

		for (int i = 0 ; i < n ; ++i)
		{
			dist[i] = 0;
			cin >> x;
			cats[i] = x;
		}
		dist[0] = 1;
		for (int i = 0 ; i < n - 1; ++i)
		{
			cin >> x >> y;
			--x; --y;
			
			v[x].push_back(y);
			v[y].push_back(x);
			
		}
		ans = 0;
		visited.assign(n, 0);
		dfs(0);
		visited.clear();
		visited.assign(n, 0);
		dfs2(0, cats[0]);
		cout << ans << '\n';
		v.clear();
		visited.clear();
	}
}
