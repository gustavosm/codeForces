#include <bits/stdc++.h>


using namespace std;


vector<int> v;
vector<pair<int, int> > p;
int n;

int gcd(int a, int b)
{
	return (b? gcd(b, a % b) : a);
}
int bk(int idx)
{
	if (idx == n) return 0;
	if (idx < 0) return 0;
	int mdc = gcd(v[p[idx].first], v[p[idx].second]);
	if (mdc > 1)
	{
		v[p[idx].first] /= mdc;
		v[p[idx].second] /= mdc;
		int ret = max(1 + bk(idx), bk(idx - 1));
		
		v[p[idx].first] *= mdc;
		v[p[idx].second] *= mdc;
		return ret;		
	}
	else
		return bk(idx + 1);
}

int main()
{
	int m;
	
	cin >> m >> n;
	for (int i = 0 ; i < m; ++i)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	for (int i = 0 ; i < n; ++i)
	{
		int x, y;
		
		cin >> x >> y;
		--x; --y;
		
		p.push_back(make_pair(x, y));
	}
	
	cout << bk(0) << '\n';
}
