#include <bits/stdc++.h>


using namespace std;

typedef long long ll;


ll dp[505][505][2];

int n;

ll c[505];
const ll INF = (1LL << 60);

ll calc(int i, int k, int jafui)
{
	ll &ans = dp[i][k][jafui];
	
	if (k == 0) return ans = 0;
	if (i == n) return ans = -INF;
	
	
	if (ans == -1)
	{
		ans = c[i] + calc(i + 1, k - 1, 1);
		if (jafui)
		{
			for (int j = i + 1; j < n; ++j)
				ans = max(ans, c[j] + calc(j + 1, k - 1, 1) - llabs(c[j] - c[i - 1]) * (j - i));
		}
		else ans = max(ans, calc(i + 1, k, 0));
	}
	return ans;	
}

void build(int i, int k, int jafui)
{
	if (k == 0 || i == n) return;
	
	if (dp[i][k][jafui] == dp[i + 1][k - 1][1] + c[i])
	{
		printf("%d ", i + 1);
		build(i + 1, k - 1, 1);
	}
	else 
	{
		if (jafui)
		{
			for (int j = i + 1; j < n ; ++j)
			{
				if (dp[i][k][jafui] == c[j] + dp[j + 1][k - 1][1] - llabs(c[j] - c[i - 1]) * (j - i))
				{
					printf("%d ", j + 1);
					build(j + 1, k - 1, 1);
				}
			}
		}
		else
			build(i + 1, k, 0);
	}
}

int main()
{
	//ios_base :: sync_with_stdio(0);
	//cin.tie(0);
	
	int k;
	scanf("%d %d", &n, &k);
	for (int i = 0 ; i < n ; ++i)
		scanf("%I64d", &c[i]);
	
	memset(dp, -1, sizeof dp);
	printf("%I64d\n", calc(0, k, 0));
	build(0, k, 0);
	puts("");
}
