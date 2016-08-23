#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

const ll maxn = 2000000;

set<pair<ll, ll> > ans;
/*
se x for numero de quadrados formados no tabuleiro n por m, entao
x = (3 * m * n * n + 3 * m * n - n * n * n + n) / 6 ->
6x = 3 * m * n * n + 3 * m * n - n * n * n + n ->
6x / n = 3 * m * n + 3 * m - n * n + 1 ->
6x / n + n^2 - 1 = m * (3 * n + 3) ->
m = (6x + n ^ 3 - n) / (3 * n^2 + 3n).
m existe <=> (6x + n ^ 3 - n) % (3 * n ^ 2 + 3n) == 0
*/
int main()
{
	ll n, m;
	ll x;
	
	cin >> x;
	
	for (n = 1; n <= maxn; ++n)
	{
		ll numerador = (6 * x + (n * n * n) - n);
		ll denominador = ((3 * n * n) + (3 * n));
		if (numerador % denominador == 0)
		{
			m = numerador / denominador;
			if (n <= m)
			{
				ans.insert(make_pair(n, m));
				ans.insert(make_pair(m, n));
			}
		}
	}
	cout << ans.size() << '\n';
	for (set<pair<ll, ll> > :: iterator it = ans.begin(); it != ans.end(); ++it)
		cout << it->first << ' ' << it->second << '\n';
}
