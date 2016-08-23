#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;

vector<pll> v;
ll valor[1000005];
vector<ll> ans;
int main()
{
	int cases;
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> cases;
	
	while (cases--)
	{
		ll n, m;
		
		cin >> n >> m;
		memset(valor, 0, sizeof valor);
		ll x;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			valor[x] += x;
		}
		
		for (int i = 1; i <= 1000000; ++i) if (valor[i])
			v.push_back(make_pair(-valor[i], -i));
			
		sort(v.begin(), v.end());
		
		for (int i = 0 ; i < (int)v.size() && m > 0; ++i)
		{
			m += v[i].first;
			ans.push_back(abs(v[i].second));
		}
		
		if (m > 0) cout << "Impossible\n";
		else
		{
			sort(ans.begin(), ans.end());
			for (int i = 0 ; i < (int)ans.size(); ++i)
			{
				if (i) cout << ' ';
				cout << ans[i];
			}
			cout << '\n';
		}
		
		ans.clear();
		v.clear();
	}
}
