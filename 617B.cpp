#include <bits/stdc++.h>

#define pb push_back
using namespace std;

typedef long long ll;

typedef vector<ll> vi;

typedef pair<ll, ll> ii;


vi v;
int main()
{
	int n;
	cin >> n;
	int x;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		if (x == 1)
			v.pb(i);
	}
	
	
	if ((int)v.size() == 0) cout << 0 << '\n';
	else if ((int)v.size() == 1) cout << 1 << '\n';
	else
	{
		ll ans = 1;
		for (int i = 0 ; i < v.size() - 1; ++i)
			ans *= (v[i + 1] - v[i]);
		cout << ans << '\n';
	}
	
}
