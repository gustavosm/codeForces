#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long ll;
ll lim = (1LL << 63);

ll mypow(ll b, int p)
{
	ll ans = 1;
	ll teto = lim / b;
	while (p--)
	{
		if (ans >= teto) return lim;
		ans *= b;
	}
	return ans;
}
int main()
{
	ll l, r, k;
	
	while (cin >> l >> r >> k)
	{
		int i = 0;
		ll pw;
		int flag = 0;
		while ( (pw = mypow(k, i)) <= r)
		{
			if (pw >= l)
			{
				cout << pw << ' ';
				flag = 1;
			}
			++i;
		}
		
		if (!flag) cout << -1;
		cout << '\n';
		
	}
}
