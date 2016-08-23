#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll x, y;
	
	int ans = 0;
	
	vector<pair<ll, ll> > v;
	
	for (int i = 0 ; i < 3; ++i)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	
	sort(v.begin(), v.end());
	
	if (v[0] == v[1] && v[1] == v[2]) cout << 1 << '\n';
	else if (v[0] == v[1] && v[1] != v[2]) cout << 
}
