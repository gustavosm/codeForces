#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t[105][105];
	
	int n;
	
	int x1, y1, x2, y2;
	
	while(cin >> n)
	{
		for (int i = 0 ; i < 105 ; i++)
		{
			for (int j = 0 ; j < 105; j++)
				t[i][j] = 0;
		}
		for (int z = 0 ; z < n ; z++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			
			for (int i = 101 - y1; i >= 101 - y2; i--)
			{
				for (int j = 101 - x1; j >= 101 - x2; j--)
					t[i][j]++;
			}
		}
		int ans = 0;
		for (int i = 1 ; i <= 100; i++)
		{
			for (int j = 1 ; j <= 100; j++)
				ans += t[i][j];
		}
		cout << ans << '\n';
	}
}
