#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

ll m[2000006];
int main()
{
	ll n;
	ll p;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	memset(m, 0LL, sizeof m);

	for (int i = 0 ; i < n ; ++i)
	{
		cin >> p;
		++m[p];
	}
	ll steps = 0;
	for (int i = 0; i < 2000000; ++i)
	{
		ll tot = m[i];
		m[i] = (m[i] & 1);
		m[i + 1] += tot / 2;
	}
	for (int i = 0; i < 2000000; ++i)
	{
		if (m[i] >= 1) ++steps;
	}
	cout << steps << '\n';
}

