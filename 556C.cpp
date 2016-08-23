#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pa(ll a1, ll an)
{
	return (a1 + an) *(an - a1 + 1) / 2;
}

int order(vector<ll> v, ll n)
{
	for (int i = 0 ;  i < n ; i++)
		if (v[i] != i + 1) return i;
	return n;
}

int main()
{
	vector<vector<ll> > v;
	
	int n, k;
	int sz, x;
	
	
	cin >> n >> k;
	ll ans = 0;
	ll numvet = 0;
	v.assign(k, vector<ll> ());
	int flag = 0;
	
	for (int i = 0 ; i < k; i++)
	{
		cin >> sz;
		
		for (int j = 0 ; j < sz; j++)
		{
			cin >> x;
			v[i].push_back(x);
		}
		int r = order(v[i], sz);
		if (r != sz) 
		{		
			numvet += sz - r;
			if (r) --r;
			
			ans += pa(1, sz - 1 - r);
		}
		else flag = 1, ++numvet;
	}
	ans += numvet - 1;
	
	cout << ans << '\n';	
}
