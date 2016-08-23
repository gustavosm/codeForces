#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
vector<pair<ll, ll> > v;


int main()
{
	ll n;
	ll x1, x2;
	ll a, b;
	
	cin >> n;
	
	cin >> x1 >> x2;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> a >> b;
		
		ll y1 = a * x1 + b;
		ll y2 = a * x2 + b;
		
		v.push_back(make_pair(y1, y2));
	}
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n - 1; ++i)
	{
		if (v[i].second > v[i + 1].second)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}
