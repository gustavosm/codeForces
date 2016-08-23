#include <bits/stdc++.h>


using namespace std;


typedef long long ll;
typedef pair<ll, ll> pll;

inline int valido(pll &a, pll &b)
{
	return a.first < b.second;
}

pll v[500005];

int main()
{
	pll p;
	
	int n;
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> v[i].second >> v[i].first;

	sort(v, v + n);

	int i = 1;
	int ans = 1;
	p = v[0];

	while (i < n)
	{
		if (valido(p, v[i]))
		{
			p = v[i];
			++ans;
		}
		++i;
	}

	cout << ans << '\n';
}
