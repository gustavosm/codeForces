#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
vector<pair<ll ,ll> > v;
int main()
{
	ll x, y;
	ll n, d;
	
	cin >> n >> d;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x >> y;
		
		v.push_back(make_pair(x, y));
	}
	
	sort(v.begin(), v.end());
	
	ll maior; ll menor;
	
	maior = menor = v[n - 1].first;
	
	ll sum = v[n - 1].second;
	ll ans = -1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (maior - v[i].first <= d)
		{
			menor = v[i].first;
			sum += v[i].second;
		}
		else
		{
			ans = max(ans, sum);
			sum = v[i].second;
			
			maior = menor = v[i].first;
		}
	}
	
	ans = max(ans, sum);
	
	cout << ans << '\n';
}
