#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

const ll INF = (1LL << 60);

ll dp[1005][1005][11][2];

string a, b;
int n, m;

ll calc(int i, int j, int ainda_tem, int x)
{
	if (ainda_tem == 0) return 0LL;
	if (i == n || j == m) return -INF;
	
	ll &ans = dp[i][j][ainda_tem][x];
	if (ans == -1)
	{
		if (x)
			ans = max(calc(i + 1, j, ainda_tem - 1, 0), calc(i, j + 1, ainda_tem - 1, 0));
		else 
			ans = max(calc(i + 1, j, ainda_tem, 0), calc(i, j + 1, ainda_tem, 0));
		
		if (a[i] == b[j])
			ans = max(ans, max(calc(i + 1, j + 1, ainda_tem - 1, 0), calc(i + 1, j + 1, ainda_tem, 1)) + 1);
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int k;
	cin >> n >> m >> k;
	cin >> a;
	cin >> b;
	
	memset(dp, -1, sizeof dp);
	cout << calc(0, 0, k, 0) << '\n';
}
