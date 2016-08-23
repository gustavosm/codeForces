#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

map<ll, ll> direita, esquerda;


ll v[200006];

int main()
{
	int n, k;
	ll ans = 0;
	while (cin >> n >> k)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> v[i];
			++direita[v[i]];
		}
		ans = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			--direita[v[i]];
			if (v[i] % k == 0)
			{
				ll x = v[i] / k;
				ll y = v[i] * k;
				
				ll qt1 = esquerda[x];
				ll qt2 = direita[y];
				
				ans += qt1 * qt2;
			}
			++esquerda[v[i]];
		}
		cout << ans << '\n';
		esquerda.clear();
		direita.clear();
	}
}
