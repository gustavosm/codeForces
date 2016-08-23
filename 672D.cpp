#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll v[500005];
ll k;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n;	
	cin >> n >> k;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> v[i];
	
	ll b = 1, e = 2000000000LL;
	ll mid;
	
	while (b < e)
	{
		mid = (b + e) >> 1;
		if (b == mid) ++mid;
		
		ll sum = 0;
		for (int i = 0 ; i < n; ++i)
			sum += max(0LL, mid - v[i]);
			
		if (sum <= k)
			b = mid;
		else e = mid - 1;
		
	}
	mid = b;
	ll sum = k;
	for (int i = 0 ; i < n ; ++i)
	{
		sum -= max(0LL, mid - v[i]);
		v[i] = max(v[i], mid);
	}
	for (int i = 0 ; i < n; ++i)
		if (sum && v[i] == mid) 
			--sum, ++v[i];
	
	b = 1, e = 2000000000LL;
		
	while (b < e)
	{
		mid = (b + e) >> 1;
		
		ll sum = 0;
		for (int i = 0 ; i < n; ++i)
			sum += max(0LL, v[i] - mid);
			
		if (sum <= k)
			e = mid;
		else b = mid + 1;
	}
	mid = b;
	
	sum = k;
	for (int i = 0 ; i < n ; ++i)
	{
		sum -= max(0LL, v[i] - mid);
		v[i] = min(v[i], mid);
	}
	for (int i = 0 ; i < n; ++i)
		if (sum && v[i] == mid) 
			--sum, --v[i];
	
	cout << *max_element(v, v + n) - (*min_element(v, v + n) ) << '\n';	
	
}
