#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

ll dig[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll digitos(ll num)
{
	ll ans = 0;
	
	while (num)
	{
		ans += dig[num % 10];
		num /= 10;
	}
	return ans;
}

int main()
{
	ll a, b;
	
	cin >> a >> b;
	ll ans = 0;
	
	for (ll i = a; i <= b; ++i)
	{
		ans += digitos(i);
	}
	cout << ans << '\n';
}
