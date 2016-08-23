#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> ii;
int main ()
{
	ll n, k, room = 0;
	
	ll x;
	
	cin >> n >> k;
	
	ll pts = 0;
	vector<ii > v;
	
	room = 10 * n;
	
	for (int i = 0; i < n; ++i) 
	{
		cin >> x;
		v.push_back(ii(10 - (x % 10), x));
		pts += (x / 10);
		room -= (x / 10);
	}
	
	sort(v.begin(), v.end());
	
	
	for (int i = 0 ; i < n && k > 0; ++i)
	{
		if (v[i].second < 100) 
		{		
			ll dec = min(v[i].first, k);
		
			v[i].first -= dec;
		
			k -= dec;
		
			if (v[i].first == 0) 
			{ 
				++pts;
				--room; 
			}
		}
	}
	
	if (k > 0 && room > 0) 
		pts += min(k / 10, room);
		
	cout << pts << '\n';
}
