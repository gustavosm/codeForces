#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
const ll N = (ll)(1e6) + 5;

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
		for (; b; b -= (b & (-b))) sum ^= ft[b];
		return sum; 
	}
	
	ll rsq(ll a, ll b) 
	{
		return rsq(b) ^ (a == 1 ? 0 : rsq(a - 1)); 
	}
	
	void adjust(ll k, ll v) 
	{
		for (; k < (int)ft.size(); k += (k & (-k))) ft[k] ^= v; 
	}
};

FenwickTree ft;

ll xorsum[N];
ll v[N];
ll ans[N];

vector<vector<pair<ll, int> > > q;

map<ll, int> last;

int main()
{
	int n, m;
	ll l, r;
	
	scanf("%d", &n);
	xorsum[0] = 0;
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%I64d", &v[i]);
		xorsum[i] = v[i];
		if (i) xorsum[i] ^= xorsum[i - 1];
	}
	scanf("%d", &m);
	
	q.assign(n + 5, vector<pair<ll, int> >());
	for (int i = 1 ; i <= m; ++i)
	{
		scanf("%I64d %I64d", &l, &r);
		q[r].push_back(make_pair(l, i));
	}
	ft.init(n);
	
	for (int i = 1 ; i <= n ; ++i)
	{
		int &lst = last[v[i]];
		if (lst)
			ft.adjust(lst, v[i]);
		ft.adjust(i, v[i]);
		
		lst = i;
		r = i;
		for (int j = 0 ; j < (int)q[i].size(); ++j)
		{
			l = q[i][j].first;
//			cerr << "olhando para " << i << ' ' << j << '\n';
			ans[q[i][j].second] = xorsum[r] ^ (l ? xorsum[l - 1] : 0) ^ ft.rsq(l, r);
		}
	}
	for (int i = 1 ; i <= m; ++i)
		printf("%I64d\n", ans[i]);
}
