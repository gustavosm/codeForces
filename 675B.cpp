#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);

	ll x1, x2, x4, x5;
	
	ll n;
	ll a, b, c, d;
	
	cin >> n >> a >> b >> c >> d;
	
	ll ans = 0;
	for (ll x1 = 1; x1 <= n; ++x1)
	{
		x2 = x1 + b - c;
		x4 = x1 + a - d;
		x5 = x1 + a + b - c - d;
		
		if (1 <= x2 && x2 <= n)
			if (1 <= x4 && x4 <= n)
				if (1 <= x5 && x5 <= n)
					ans += n;
	}
	
	cout << ans << '\n';
}
