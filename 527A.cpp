#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main ()
{
	ll a;
	ll b;
	ll ans;
	cin >> a >> b;
	if (a%b == 0) cout << a/b << '\n';
	else 
	{
		ans = 0;
		while(b > 0)
		{
			ans+= a/b;
			ll aux = a;
			a = b;
			b = aux%b;
		}
		cout << ans << '\n';
	}
}
