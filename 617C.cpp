#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

typedef vector<ll> vi;

typedef pair<ll, ll> ii;


vi v1, v2;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main()
{
	int n;
	ll x1, y1, x2, y2;
	
	cin >> n >> x1 >> y1 >> x2 >> y2;
	
	ll x, y;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x >> y;
		
		ll d1 = dist(x1, y1, x, y);
		ll d2 = dist(x2, y2, x, y);
		
		if (d1 > d2)
			v2.push_back(d2);
		else v1.push_back(d1);
	}
	
}
