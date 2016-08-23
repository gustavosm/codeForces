#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mid(ll a, ll b, ll c)
{
	if (a <= max(b, c) && a >= min (b, c)) return a;
	if (b <= max(a, c) && b >= min (a, c)) return b;
	if (c <= max(b, a) && c >= min (b, a)) return c;
}
int main()
{
	ll r, g, b;
	
	while (cin >> r >> g >> b)
	{
		ll mx = max(r, max(g, b));
		
		ll mn = min(r, min(g, b));
		
		ll meio = mid(r, g, b);
		
		ll ans = mn;
		
		mx -= mn;
		meio -= mn;
		
		if (meio >= 2)
		{
			ans += meio / 2;
		}
		else
		{
		 	if (mx > 1)
				ans += meio;
		}
		cout << ans << '\n';
	}
}
