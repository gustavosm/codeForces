#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

vector<vector<pair<ll, int> > > v;
vector<int> bbb;
int lala[100005];
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	ll ans;
	
	int n, m, k;
	int u, q;
	ll w;
	
	
	ans = (1LL << 60);
	cin >> n >> m >> k;
	v.assign(n, vector<pair<ll, int> >());
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> u >> q >> w;
		--q, --u;
		v[u].push_back(make_pair(w, q));
		v[q].push_back(make_pair(w, u));
	}	
	if (!k) cout << -1 << '\n';
	else
	{
		for (int i = 0 ; i < k ; ++i)
		{
			cin >> u;
			--u;
			lala[u] = 1;
			bbb.push_back(u);
		}
		for (int i = 0 ; i < k; ++i)
		{
			u = bbb[i];	
			for (int j = 0 ; j < (int)v[u].size(); ++j)
				if (!lala[v[u][j].second])
					ans = min(ans, v[u][j].first);
		}
		if (ans == (1LL << 60)) ans = -1;
		cout << ans << '\n';
	}
}
