#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
typedef long long int ll;


class DateToIdx
{
	vector<ll> ordenado;
	
public:
	DateToIdx(){}
	DateToIdx(vector<ll>& origin)
	{
		ordenado = origin;
		sort(ordenado.begin(), ordenado.end());
	}
		
	ll operator [](const ll val) const
	{
		return (ll)(lower_bound(ordenado.begin(), ordenado.end(), val) - ordenado.begin());
	}
};

class SegTree
{
public:
	void build(int _n)
	{
		memset(st, 0, sizeof st);
		n = _n;
	}
	
	ll query(int b, int e)
	{
		return query(1, 0, n - 1, b, e);
	}
	
	void update(int b, ll e)
	{
		update(1, 0, n - 1, b, e);
	}
private:
	ll st[4 * MAXN];
	int n;
	
	ll query(int idx, int b, int e, int i, int j)
	{
		if (b > j || e < i) return (ll)INT_MIN;
		if (b >= i && e <= j) return st[idx];
		
		int mid = (b + e) >> 1;
		int cl = (idx << 1);
		int cr = cl + 1;
		
		return max(query(cl, b, mid, i, j), query(cr, mid + 1, e, i, j));
	}
	
	void update(int idx, int b, int e, int i, ll val)
	{
		
		if (b > i || e < i) return;
		if (b == e && e == i) st[idx] = max(st[idx], val);
		else
		{
			int mid = (b + e) >> 1;
			int cl = (idx << 1);
			int cr = cl + 1;
			
			update(cl, b, mid, i, val);
			update(cr, mid + 1, e, i, val);
			
			st[idx] = max(st[cl], st[cr]);
		}
	}
};

SegTree seg;
DateToIdx dtoid;

vector<ll> d, v, t;

ll process(int n)
{

	for (int i = 0 ; i < n ; ++i)
		cin >> d[i] >> v[i] >> t[i];
		
	dtoid = DateToIdx(d);
	
	seg.build(n);
	
	for (int i = 0 ; i < n; ++i)
	{
		//cout << "id de " << d[i] << " eh " << dtoid[d[i]] << '\n';
		//cout << "update " << dtoid[d[i]] << " pra max(" << seg.query(dtoid[d[i]], dtoid[d[i]]) << ", " << v[i] + seg.query(dtoid[d[i] - t[i]], dtoid[d[i]]) << ")\n";
		seg.update(dtoid[d[i]], v[i] + seg.query(dtoid[d[i] - t[i]], dtoid[d[i]]));
	}
	
	return seg.query(0, n);
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n;
	
	cin >> n;
	
	d.assign(n, 0LL);
	v.assign(n, 0LL);
	t.assign(n, 0LL);
	
		
	cout << process(n) << '\n';
}
