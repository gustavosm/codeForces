#include <bits/stdc++.h>

using namespace std;

char g[1005][1005];

vector<int> r[1005];
vector<int> c[1005];

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	int bomb = 0;
	
	char d;
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++i) for (int j = 0 ; j < m ; ++j)
	{
		cin >> d;
		g[i][j] = d;
		if (d == '*')
		{
			r[i].push_back(j);
			c[j].push_back(i);
			++bomb;
		}
	}
	
	for (int i = 0 ; i < n ; ++i) for (int j = 0 ; j < m ; ++j)
	{
		int explode = (int)r[i].size() + (int)c[j].size();
		if (explode - (g[i][j] == '*') == bomb)
		{
			cout << "YES\n" << i + 1 << ' ' << j + 1 << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}
