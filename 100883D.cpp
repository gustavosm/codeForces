#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll v[1000005];
ll k;
ll n;

bool ok(ll m)
{
	ll pessoas = 0;
	
	ll mx = -1;
	ll qtd = 0;
	
	for (int i = 0 ; i < n; ++i)
	{
		//if (v[i] > m) return 0; nao precisa disso, pq m eh pelo menos max_elem do array
		mx = max(mx, v[i]);
		++qtd;
		
		if (mx * qtd > m)
		{
			++pessoas;
			mx = -1;
			qtd = 0;
			--i;
		}
	}
	return pessoas < k;
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n >> k;
		ll e = -1;
		for (int i = 0 ; i < n ; ++i)
			cin >> v[i], e = max(e, v[i]);
		
		ll b = e;
		e *= (n);
		
		ll mid;
		while (b < e)
		{
			mid = (b + e) >> 1;
			
			if (ok(mid)) e = mid;
			else b = mid + 1;
		}
		cout << e << '\n';		
	}
}
