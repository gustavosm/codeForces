#include <bits/stdc++.h>

using namespace std;
#define INF 99999999LL
#define pb push_back
#define make_pair mp
#define sz size

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpl;
typedef vector<vpl> vvpl;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n, k, a, b, c, d;
	cin >> n >> k;
	
	if (n == 4 || k <= n) puts ("-1");
	else
	{
		cin >> a >> b >> c >> d;
		
		cout << a << ' ' << c << ' ';
		for (int i = 1; i <= n; ++i)
			if (i != a && i != b && i != c && i != d) cout << i << ' ';
		
		cout << d << ' ' << b << '\n';
		cout << c << ' ' << a << ' ';
		for (int i = 1; i <= n; ++i)
			if (i != a && i != b && i != c && i != d) cout << i << ' ';
		
		cout << b << ' ' << d << '\n';
	}
	return 0;
}
