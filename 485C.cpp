#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long ll;

int main()
{
	int n;
	
	ll x, y;
	
	ll ans;
	
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x >> y;
		
		ans = x;
		
		for (int j = 0; j < 64; ++j)
		{
			ll aux = 1;
			
			if (!(x & (aux << j)))
			{
				ans = x;
				x |= (aux << j);
				
				if (x > y) break;
			}
		}
		
		cout << ans << '\n';
	}
}
