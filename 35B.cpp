#include <bits/stdc++.h>


using namespace std;


int main()
{
	string v[35][35];
	string str;
	int op, x, y;	
	int n, m, k;
	
	#ifdef ONLINE_JUDGE	
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m >> k;
	
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < m; ++j)
		{
			v[i][j] = "";
		}
	}
	while (k--)
	{
		cin >> op;
		
		if (op > 0)
		{
			cin >> x >> y >> str;
		
			--x; --y;
			if (v[x][y].size() == 0)
				v[x][y] = str;
			else
			{
				int aux = x;
				int auy = y;
				while (v[x][y].size() != 0)
				{
					++y;
					if (y == n) y = 0, ++x;
					if (x == n)
						x = 0;
					if (x == aux && y == auy) break;
				}
				if (!(x == aux && y == auy))
					v[x][y] = str;
			}
		}
		else
		{
			cin >> str;
			
			int flag = 0;
			for (int i = 0 ; i < n; ++i)
			{
				for (int j = 0 ; j < m ; ++j)
				{
					if (str == v[i][j])
					{
						flag = 1;
						printf("%d %d\n", i + 1, j + 1);
						v[i][j] = "";
						break;
					}
				}
				if (flag) break;
			}
			if (!flag)
				printf("-1 -1\n");
		}
	}
}
