#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

ll pow_i(ll base, ll exp)
{
	ll ret = 1;
	while (exp--)
		ret *= base;
	return ret;
}
int main()
{
	ll x, y;
	ll num;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n, base;
	
	x = y = 0;
	
	cin >> n >> base;
	
	for (int i = n - 1; i >= 0; --i)
	{
		cin >> num;
		x += num * pow_i(base, i);
	}
	
	cin >> n >> base;
	
	for (int i = n - 1; i >= 0; --i)
	{
		cin >> num;
		y += num * pow_i(base, i);
	}
	
	if (x == y) cout << "=\n";
	else if (x > y) cout << ">\n";
	else cout << "<\n";
	
}
