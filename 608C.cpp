#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define INF 9999999

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;

set<ll> s;
ll v[1000005];

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int n;
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		ll x, y;
		
		cin >> x >> y;
		set<ll> :: iterator it = s.upper_bound(x - y);
		v[x] = distance(s.begin(), it);
		
		s.insert(x);
	}
	set<ll> :: iterator it = s.end();
	--it;
	int power = 1;
	int ans = 0;
	while (1)
	{
		if (
	}
	
}
