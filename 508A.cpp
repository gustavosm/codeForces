#include <bits/stdc++.h>

using namespace std;


int main()
{
	int m[1005][1005];
	
	for (int i = 0 ; i < 1005; i++)
		for (int j = 0 ; j < 1005; j++)
			m[i][j] = 0;
		
	int lose = 0;
	
	int n, m1, k;
	int x, y;
	
	cin >> n >> m1 >> k;
	
	for (int i = 1 ; i <= k ; i++)
	{
		cin >> x >> y;
		
		m[x][y] = 1;
		if (m[x + 1][y] == 1 && m[x + 1][y - 1] == 1 && m[x][y - 1] == 1)
			if (!lose) lose = i;
		if (m[x + 1][y] == 1 && m[x][y + 1] == 1 && m[x + 1][y + 1] == 1)
			if (!lose) lose = i;
		if (m[x - 1][y + 1] == 1 && m[x][y + 1] == 1 && m[x - 1][y] == 1)
			if (!lose) lose = i;
		if (m[x - 1][y] == 1 && m[x][y - 1] == 1 && m[x - 1][y - 1] == 1)
			if (!lose) lose = i;
	}
	
	cout << lose << '\n';
}
