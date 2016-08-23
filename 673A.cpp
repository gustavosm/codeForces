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
	
	int n;
	int x;
	cin >> n >> x;
	if (x > 15) cout << 15 << '\n';
	else
	{
		int y;
		for (int i = 1; i < n ; ++i)
		{
			cin >> y;
			if (y - x > 15) 
			{
				cout << x + 15 << '\n';
				return 0;
			}
			x = y;
		}
		
		if (x + 15 > 90) cout << 90 << '\n';
		else cout << (x + 15) << '\n';
	}
	return 0;
}
