#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int main()
{
	vector<pair<ll, ll> > v;
	
	ll x, y;
	
	int n;
	
	cin >> n;
	
	for (int i = 0 ; i < n; ++i)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	ll ans = 0;
	for (int i = 0 ; i < n ;)
	{
		ll sum = 0;
		int a = i;
		while (i < n && v[a].second <= v[i].second)
		{
			sum += v[i].first;
			++i;
		}
		
		ans += sum * v[a].second;
	}
	cout << ans << '\n';
	
	v.clear();
}
