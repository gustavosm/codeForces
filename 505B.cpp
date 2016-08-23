#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int> > > v;
vector<int> visited;

void dfs(int s, int c)
{
	if (visited[s]) return;
	visited[s] = 1;
	for (int i = 0 ; i < v[s].size(); i++)
	{
		if (v[s][i].first == c)	
			dfs(v[s][i].second, c);
	}
}
int main()
{
	int n;
	int m;
	int u;
	int v1;
	int c;
	int q;
	int ans;
	
	while(cin >> n >> m)
	{
		v.assign(n, vector<pair<int,int> >());
		for (int i = 0 ; i < m ; i++)
		{
			cin >> u >> v1 >> c;
			--u;
			--v1;
			v[u].push_back(make_pair(c, v1));
			v[v1].push_back(make_pair(c, u));
		}
		visited.assign(n, 0);
		cin >> q;
		for (int k = 0 ; k < q; k++)
		{
			cin >> u >> v1;
			--u;
			--v1;
			ans = 0;			
			for (int i = 1; i <= m; i++)
			{
				dfs(u, i);
				ans+= visited[v1];
				for (int j = 0 ; j < n ; j++) visited[j] = 0;
				
			}
			cout << ans << '\n';
		}
		v.clear();
		visited.clear();
	}
}
