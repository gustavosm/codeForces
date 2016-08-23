#include <bits/stdc++.h>


using namespace std;

int v[4005][4005];
int grau[4005];
vector<pair<int, int > > edges;

int main()
{
	int n, m;
	int u, w;
	
	
	while (cin >> n >> m)
	{
		edges.clear();
		
		for (int i = 0 ; i < n ; ++i) {for (int j = 0 ; j < n ; ++j) v[i][j] = 0; grau[i] = 0;}
		for (int i = 0 ; i < m; ++i)
		{
			cin >> u >> w;
			
			--u; --w;
			edges.push_back(make_pair(u, w));
			
			++grau[u];
			++grau[w];
			v[u][w] = 1;
			v[w][u] = 1;
		}
		int sum = INT_MAX;
		for (int i = 0 ; i < m; ++i)
		{
			int flag = 0;
			u = edges[i].first;
			w = edges[i].second;
			for (int j = 0 ; j < n ; ++j)
			{
				if (j == u || j == w) continue;
				
				if (v[j][u] && v[j][w])
				{
					sum = min(sum, grau[j] + grau[u] + grau[w] - 6);
				}
				
			}
		}
		if (sum == INT_MAX) cout << "-1\n";
		else cout << sum << '\n';

		
	}
}
