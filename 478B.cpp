#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pa(ll s)
{
	--s;
	if (s < 0) return 0;
	
	return (ll)(((1 + s) * s) / 2);
}
int main()
{
	ll n, m;
	
	while (cin >> n >> m)
	{
		ll menor;
		menor = (m - n % m) * pa( n / m ) + ( n %m ) * pa(n / m  + 1);
		ll maior = pa(n - (m - 1));
		
		cout << menor << ' ' << maior << '\n';
	}
}
