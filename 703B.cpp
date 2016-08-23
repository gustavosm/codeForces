#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

class FenwickTree 
{
private: 
	vi ft;
public:	
	void init(ll n) 
	{
		ft.assign(n + 1, 0); 
	}
	
	ll rsq(ll b) 
	{
		ll sum = 0; 
		for (; b; b -= (b & (-b))) sum += ft[b];
		return sum; 
	}
	
	ll rsq(ll a, ll b) 
	{
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
	}
	
	void adjust(ll k, ll v) 
	{
		for (; k < (int)ft.size(); k += (k & (-k))) ft[k] += v; 
	}
};

FenwickTree ft;

ll val[100005];
ll c[100005];

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	
	cin >> n >> k;
	ll id;
	ft.init(n);
	for (int i = 1 ; i <= n ; ++i)
	{
		cin >> val[i];
		ft.adjust(i, val[i]);
	}
	ll ans = 0;
	memset(c, 0, sizeof c);
	
	for (int i = 0 ; i < k ; ++i)
	{
		cin >> id;
		c[id] = 1;
		ll sum = 0;
		ft.adjust(id, -val[id]);
		if (id > 1)
			sum += ft.rsq(1, id - 1);
		if (id < n)
			sum += ft.rsq(id + 1, n);
		ans += val[id] * sum;
	}
	
	for (int i = 1 ; i < n ; ++i)
	{
		if (!c[i] && !c[i + 1])
			ans += val[i] * val[i + 1];
	}
	if (!c[1] && !c[n])
		ans += val[1] * val[n];
		
	cout << ans << '\n';
	
}
