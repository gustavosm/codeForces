#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

int main()
{
	ll n, x;
	ll ans;
	while (cin >> n >> x)
	{
		ans = 0;
		for (ll i = 1; i <= n ; ++i)
		{
			if (!(x % i))
				if (x / i <= n) ++ans;
		}
		cout << ans << '\n';
	}	
}
