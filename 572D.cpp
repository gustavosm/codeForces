#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct point
{
	ll x;
	ll peso;
	point(){}
	point(ll _x, ll p) : x(_x), peso(p) {}
	
	bool operator < (const point &other) const
	{
		return (x + peso) < (other.x + other.peso);
	}
};

vector<point> v;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n;
	
	ll x, p;
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x >> p;
		v.push_back(point(x, p));
	}
	
	sort(v.begin(), v.end());
	
	int last = 0, ans = 1;
	for (int i = 1 ; i < n ; ++i)
	{
		if (v[i].x - v[i].peso >= v[last].x + v[last].peso)
		{
			last = i;
			++ans;
		}
	}
	
	cout << ans << '\n';
}
