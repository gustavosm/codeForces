#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

typedef pair<ll, ll> pl;


ll mxx, mxy, mnx, mny;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	pl x;
	pl mx, mn;
	
	int cases;
	cin >> cases;
	
	while (cases--)
	{
		int n;
		cin >> n;
		mxx = mxy = -2000;
		mny = mnx = 2000;
		
		for (int i = 0 ; i < n ; ++i)
		{
			ll x, y;
			for (int j = 0 ; j < 4; ++j)
			{
				cin >> x >> y;
				mxx = max(mxx, x);
				mnx = min(mnx, x);
				mxy = max(mxy, y);
				mny = min(mny, y);				
			}
		}
		
		cout << (mxx - mnx) * (mxy - mny) << '\n';
	}	
}
