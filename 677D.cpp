#include <bits/stdc++.h>


using namespace std;

#define INF 999999999LL

typedef long long ll;

ll x[305][905];
ll y[305][905];
ll sz[905];

ll dp[305][305];

ll p;
ll n, m;

ll calc(ll tipo, ll p1, ll p2)
{
	if (tipo == p)
		return 0LL;
	
	ll ans;
	if (p1 == -1) ans = -1;
	else ans = dp[p1][p2];
	
	if (ans == -1)
	{
		ans = INF;
	
		++tipo;
		ll tam = sz[tipo];
		for (int i = 0 ; i < tam; ++i)
		{
			ll xx = x[tipo][i];
			ll yy = y[tipo][i];
			
			ll ret = calc(tipo, xx, yy);
			ans = min(ans, ret + abs(p1 - xx) + abs(p2 - yy));
		}
	}
	if (p1 == -1) return ans;
	else return dp[p1][p2] = ans;
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> p;
	ll x1;

	memset(sz, 0, sizeof sz);
		
	for (int i = 0; i < n; ++i) for (int j = 0 ; j < m ; ++j)
	{
		cin >> x1;
		x[x1][sz[x1]] = i;
		y[x1][sz[x1]++] = j;	
	}
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(0, -1, -1) - 2 << '\n';
}
