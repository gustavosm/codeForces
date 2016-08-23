#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

typedef pair<ll, ll> pl;

map<pl, ll> m;
int a[2005];
int b[2005];

int main()
{
	int n;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n;	
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> a[i] >> b[i];
	}
	
	for (int i = 0 ; i < n ; ++i) for (int j = i + 1 ; j < n ; ++j)
	{
		pl p(a[i] + a[j], b[i] + b[j]);
		++m[p];
	}
	
	ll ans = 0;
	for (map<pl, ll> :: iterator it = m.begin(); it != m.end(); ++it)
	{
		ll o = (it->second);
		
		ans += (o * (o - 1)) / 2;
	}
	cout << ans << '\n';
}
