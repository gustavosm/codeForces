#include <bits/stdc++.h>


using namespace std;

int main()
{
	int v[505][505];
	int mx[505];
	
	int q, n, m;
	
	int x, y;
	
	int maior;
	int um;
	
	while (cin >> n >> m >> q)
	{
		for (int i = 0 ; i < n ; ++i)
		{	
			um = 0;
			maior = INT_MIN;
			for (int j = 0 ; j < m ; ++j)
			{
				cin >> v[i][j];
				
				if (v[i][j]) ++um;
				
				else
				{
					if (maior < um) maior = um;
					um = 0;
				}
			}
			mx[i] = max(maior, um);
		}
		while (q--)
		{
			cin >> x >> y;
			--x; --y;
			v[x][y] ^= 1;
			um = 0;
			maior = INT_MIN;
			
			for (int j = 0 ; j < m ; ++j)
			{
				if (v[x][j]) ++um;
				
				else
				{
					maior = max(maior, um); um = 0;
				}
			}
			mx[x] = max(maior, um);
			
			maior = INT_MIN;
			for (int i = 0; i < n; ++i) maior = max(maior, mx[i]);
			
			cout << maior << '\n';
		}
	}
}
