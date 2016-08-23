#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

typedef vector<ll> vl;


ll mdc(ll a, ll b)
{
	return (b ? mdc(b, a % b) : a);
}
int main()
{
	ll l, r;
	
	cin >> l >> r;
	
	for (ll i = l; i <= r; ++i)
	{
		for (ll j = i + 1; j <= r; ++j)
		{
			if (mdc(i, j) == 1)
			{
				for (ll k = j + 1; k <= r; ++k)
				{
					if (mdc(j, k) == 1 && mdc(i, k) != 1)
					{
						cout << i << ' ' << j << ' ' << k << '\n';
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << '\n';
}
