#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int n;
	int m;
	int k;
	int player;
	int x;
	int ans;
	int bits;
	int diff;
	
	vector<int> v;
	
	while(cin >> n >> m >> k)
	{
		for (int i = 0 ; i < m ; i++)
		{
			cin >> x;
			v.push_back(x);
		}		
		cin >> player;
		ans = 0;
		for (int i = 0 ; i < m; i++)
		{
			diff = player ^ v[i];
			bits = 0;
			while (diff > 0)
			{
				if (diff % 2) bits++;
				diff/= 2;
			}
			if (bits <= k) ans++;
		}
		cout << ans << '\n';
		v.clear();
	}
}
