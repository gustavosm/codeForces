#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n, d, h;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> d >> h;
	
	if (d > 2 * h || (d == 1 && n > 2))
		cout << -1 << '\n';
	else
	{
		for (int i = 1; i <= h; ++i)
			cout << i << ' ' << (i + 1) << '\n';
		
		int root = 1;
		for (int i = 1; i <= d - h; ++i)
		{
			int node = h + 1 + i;
			cout << root << ' ' << node << '\n';
			root = node;
		}
		
		for (int i = d + 2; i <= n; ++i)
			cout << (d == h ? 2 : 1) << ' ' << i << '\n';
	}
}
