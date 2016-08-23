#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define INF 9999999

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;

vector<ii> v;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	ll n, s;
	
	cin >> n >> s;
	
	for (ll i = 0 ; i < n ; ++i)
	{
		ll x, y;
		
		cin >> x >> y;
		
		v.push_back(ii(-x, y));
	}	
	
	sort(v.begin(), v.end());
	
	ll sum = 0LL;
	ll i = 0;
	while (s > 0 && i < n)
	{
		sum += (s + v[i].first);
		s = -v[i].first;
		if (sum < v[i].second) sum += (v[i].second - sum);
		++i;
	}
	sum += s;
	cout << sum << '\n';
}
