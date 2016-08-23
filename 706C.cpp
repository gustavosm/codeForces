#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll custo[100005];

ll dp[100005][2];
int n;

string v[100005];
const ll INF = (1LL << 60);

ll calc(int i, int inv)
{
	if (i == n - 1) return 0;
	
	ll &ans = dp[i][inv];
	
	if (ans == -1)
	{
		ans = INF;
		string s1 = v[i + 1];
		string s2 = v[i];
		if (inv) reverse(s2.begin(), s2.end());
	
		if (s1 >= s2)
			ans = min(ans, calc(i + 1, 0));
		
		reverse(s1.begin(), s1.end());
		if (s1 >= s2)
			ans = min(ans, custo[i + 1] + calc(i + 1, 1));
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i) cin >> custo[i];
	for (int i = 0 ; i < n ; ++i) cin >> v[i];
	
	memset(dp, -1, sizeof dp);
	//cout << "hehehe\n";
	ll ans = min(calc(0, 0), custo[0] + calc(0, 1));
	if (ans == INF) cout << "-1\n";
	else cout << ans << '\n';
}
