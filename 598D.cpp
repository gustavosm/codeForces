#include <bits/stdc++.h>


using namespace std;

char m[1005][1005];

int vis[1005][1005];


int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int n, m1;
int chamada;
int v[1000005];

int val(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m1;
}
int flood(int i, int j)
{
	int cont = 0;
	if (m[i][j] != '.') return 0;
	if (vis[i][j] != 0) return 0;
	vis[i][j] = chamada;
	for (int k = 0 ; k < 4; ++k)
	{
		if (val(i + dr[k], j + dc[k]))
			cont += (m[i + dr[k]][j + dc[k]] == '*');
	}
	for (int k = 0 ; k < 4; ++k)
		if (val(i + dr[k], j + dc[k]))
			cont += flood(i + dr[k], j + dc[k]);
	return cont;
}

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	
	int q;
	
	cin >> n >> m1 >> q;
	
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < m1 ; ++j)
			cin >> m[i][j];
	for (int i = 0 ; i < n ; ++i)
	{
		for (int j = 0 ; j < m1; ++j)
		{
			vis[i][j] = 0;
			v[i * m1 + j] = 0;
		}
	}
	
	chamada = 1;
	for (int i = 0 ; i < n ; ++i)
	{
		for (int j = 0; j < m1 ; ++j)
		{
			if (!vis[i][j])
			{
				v[chamada] = flood(i, j);
				++chamada;
			}
		}
	}
	
	while (q--)
	{
		int i, j;
		cin >> i >> j;
		--i, --j;
		
		cout << v[vis[i][j]] << '\n';
	}
}
