#include <bits/stdc++.h>


using namespace std;

typedef long long ll;


ll mdc(ll a, ll b)
{
	return (b ? mdc(b, a % b) : a);
}
int main()
{
	ll t, w, b;
	
	
	while (cin >> t >> w >> b)
	{
	
		if (t < min(w, b)) cout << "1/1\n";
		else
		{
			if (w < b) swap(w, b);
			
			ll qtde = 1;
			for (ll x = 1; w * x <= t; ++x)
			{
				for (ll y = 1; b * y <= t; ++y)
					if (b * y == x * w)
						qtde += (b * (y + 1)) - (b * y);
			}
			ll m = mdc(qtde, t);
			cout << qtde / m << '/' << t / m << '\n';
		}
		
	}
}
