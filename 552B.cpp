#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long ll;

int main()
{
	ll n;
	
	while (cin >> n )
	{
		ll ans = 9;
		if (n < 10) 
		{
			cout << n << '\n';
			continue;
		}
		if (n == 1000000000) 
		{
			cout << "8888888899\n";
			continue;
		}
		
		if (n >= 100)
		{
			ans += (ll)(90 * 2);
		}
		else 
		{
			ans += (ll)(n - 9) * 2;
			cout << ans << '\n';
			continue;
		}
		if (n >= 1000)
		{
			ans += (ll)(900 * 3);
		}
		else 
		{
			ans += (ll)(n - 99) * 3;			
			cout << ans << '\n';
			continue;
		}
		if (n >= 10000)
		{
			ans += (ll)(9000 * 4);
		}
		else 
		{
			ans += (ll)(n - 999) * 4;
			cout << ans << '\n';
			continue;
		}
		if (n >= 100000)
		{
			ans += (ll)(90000 * 5);
		}
		else 
		{
			ans += (ll)(n - 9999) * 5;
			cout << ans << '\n';
			continue;
		}
		if (n >= 1000000)
		{
			ans += (ll)(900000 * 6);
		}
		else 
		{
			ans += (ll)(n - 99999) * 6;
			cout << ans << '\n';
			continue;
		}
		if (n >= 10000000)
		{
			ans += (ll)(9000000 * 7);
		}
		else 
		{
			ans += (ll)(n - 999999) * 7;
			cout << ans << '\n';
			continue;
		}
		if (n >= 100000000)
		{
			ans += ((ll)90000000 * (ll)8);
		}
		else 
		{
			ans += (ll)(n - 9999999) * 8;
			cout << ans << '\n';
			continue;
		}
		if (n >= 1000000000)
		{
			ans += ((ll)900000000 * (ll)9);
		}
		else 
		{
			ans += (ll)(n - 99999999) * 9;
			cout << ans << '\n';
			continue;
		}
		
		cout << ans << '\n';
	}	
}
