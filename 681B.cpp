#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	ll n;
	cin >> n;
	
	for (ll i = 0; i * 1234567 <= n; ++i)
	{
		for (ll j = 0; j * 123456 + i * 1234567 <= n; ++j)
		{
			if ((n - (j * 123456 + i * 1234567)) % 1234 == 0)
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}
