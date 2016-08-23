#include <bits/stdc++.h>


using namespace std;

typedef long double ld;
typedef long long ll;

ld dp[1 << 21];
ld m[25][25];

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int cases;
	
	cin >> cases;
	cout.precision(6);
	for (int c = 1; c <= cases; ++c)
	{
		int n;
		cin >> n;
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n ; ++j)
				cin >> m[i][j];
		}
		if (n == 1) cout << "Case " << c << ": 1.000000\n";
		else
		{
			ll mask = (1 << n) - 1;
			for (ll i = 0 ; i <= mask; ++i)
				dp[i] = 0.0;
				
			dp[mask] = 1.0;
			
			for (; mask > 0; --mask)
			{
				ll bits = __builtin_popcount(mask);
				ll games = ((bits * (bits - 1)) >> 1);
				for (int i = 0 ; i < n; ++i)
				{
					if (mask & (1 << i))
					{
						ll turn = (mask ^ (1 << i));
						for (int j = 0 ; j < n ; ++j)
							if (mask & (1 << j))
								dp[turn] += dp[mask] * m[j][i] / games;
					}
				}
			}
			cout << "Case " << c << ":";
			for (int i = 0 ; i < n; ++i)
				cout << fixed << ' ' << dp[1 << i];
			cout << '\n';
		}
	}
}
