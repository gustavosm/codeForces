#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
ll n, m;

ll process(ll x)
{
	ll ret = 0;
	
	for (int i = 1 ; i <= n; ++i) ret += min(m, (x - 1) / i);
	
	return ret;
}
int main()
{
	ll k;
	
	while(cin >> n >> m >> k)
	{
	
		ll l = 1, r = n * m + 1;
		
		while (l < r)
		{
			ll x = (l + r) >> 1;
			
			if (process(x) < k) l = x + 1;
			else r = x;
		}
		cout << l - 1 << '\n';
	}
}
