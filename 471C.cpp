#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	ll n;
	cin >> n;
	ll ans = 0;
	ll aux = 2;
	ll aumenta = 2;
	for (ll i = 1; i < n; ++i)
	{
		if (aux > n) break;
		
		if ((n + i) % 3 == 0) ++ans;
		
		aumenta += 3;
		aux += aumenta;
	}
	cout << ans << '\n';
	
}
