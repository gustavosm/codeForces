#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll qtd_elem(ll n, ll a)
{
	n = (n - n % a);
	
	return n / a;
}


int main()
{
	ll n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	
	if (p > q)
	{
		ll qtd1 = qtd_elem(n, a);
		ll qtd2 = qtd_elem(n, b) - qtd_elem(n, (a * b) / __gcd(a, b));
		
		cout << qtd1 * p + qtd2 * q << '\n';
	}
	else
	{	
		ll qtd1 = qtd_elem(n, b);
		ll qtd2 = qtd_elem(n, a) - qtd_elem(n, (a * b) / __gcd(a, b));
		
		cout << qtd1 * q + qtd2 * p << '\n';
	}
}
