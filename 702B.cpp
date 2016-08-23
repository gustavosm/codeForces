#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
unordered_map<ll, vector<ll> > freq;
const ll N = 1e5 + 5;
vector<ll> v;

int bs(vector<ll> &p, ll val)
{
	int b = 0;
	int n = (int)p.size();
	int e = n - 1;
	
	while (b < e)
	{
		int mid = (b + e) >> 1;
		if (mid && v[mid - 1] <= val && val < v[mid]) return mid;
		if (mid < n && v[mid] <= val && val < v[mid + 1]) return mid + 1;
		if (v[mid] == val) return mid + 1;
		
		if (v[mid] < val) b = mid;
		else e = mid;
	}
	return -1;
}
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	freq.reserve(N);
	
	ll n;
	
	cin >> n;
	ll x;
	ll mx = -1;
	for (ll i = 0 ; i < n ; ++i)
	{
		cin >> x;
		v.push_back(x);
		mx = max(mx, x);
		freq[x].push_back(i);
	}
	
	ll ans = 0;
	
	for (ll i = 0 ; i < n ; ++i)
	{
		for (ll j = 0; j <= 63; ++j)
		{
			ll find = (1LL << j) - v[i];
			if (find > mx) break;
			if (find > 0 && freq.count(find))
			{
				vector<ll> &aux = freq[find];
				if (find == v[i] && aux.size() == 1) continue;
				int result = aux.end() - lower_bound(aux.begin(), aux.end(), i + 1);
				ans += result;
			}
		}
	}
	cout << ans << '\n';
}
