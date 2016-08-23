#include <bits/stdc++.h>


using namespace std;


int v[100005];

int main()
{
	int n, k, a;
	int t, x;
	while (cin >> n >> k >> a)
	{
		memset(v, 0, sizeof v);
		
		cin >> t;
		int flag = 0;
		for (int i = 1 ; i <= t; ++i)
		{
			cin >> x;
			if (n - x <= a && x <= a)
			{
				flag = 1;
				cout << i << '\n';
				break;
			}
			if (!flag)
			{
				for (int j = x - a; j <= x + a; ++j)
				{
					if (j < 0) j = 0;
					else if (j >= n) break;
				
					if (v[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag)
					cout << i << '\n';
				v[x] = 1;
			}
		}
		if (!flag) cout << "-1\n";
	}
}
