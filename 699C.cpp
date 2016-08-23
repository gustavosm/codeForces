#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

const ll N = 105;
ll dp[N][5];

ll days[N];
int n;

ll calc(int day, int last)
{
	if (day == n) return 0;
	
	ll &ans = dp[day][last];
	if (ans == -1)
	{
		ans = 1 + calc(day + 1, 0);
		ll atv = days[day];
		if (atv)
		{
			if (atv == 1)
			{
				if (last != 1)
					ans = min(ans, calc(day + 1, 1));
			}
			else if (atv == 2)
			{
				if (last != 2)
					ans = min(ans, calc(day + 1, 2));
			}
			else if (atv == 3)
			{
				if (last == 1 || !last) 
					ans = min(ans, calc(day + 1, 2));
				if (last == 2 || !last) 
					ans = min(ans, calc(day + 1, 1));
			}
		}
	}
	
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	memset(dp, -1, sizeof dp);
	
	for (int i = 0 ; i < n ; ++i) cin >> days[i];

	cout << calc(0, 0) << '\n';
}
