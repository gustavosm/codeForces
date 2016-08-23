#include <bits/stdc++.h>


using namespace std;


int dp[2005][2005];

int v[2005];
int n, p;


int calc(int i , int sum)
{
	if (i == n) return 0;
	
	if ((sum + v[i]) % p == 0)
		return 1;

	int &ans = dp[i][sum];
	
	if (ans == -1)
	{
		ans = (calc(i + 1, (sum + v[i]) % p) || calc(i + 1, sum));
	}
	
	return ans;
}

int main()
{
	cin >> n >> p;
	
	n = min(n, p);
	
	
	memset(dp, -1, sizeof dp);
	
	
	for (int i = 0 ; i < n ; ++i) cin >> v[i];
	
	if (calc(0, 0))
		cout << "YES\n";
	else cout << "NO\n";
}
