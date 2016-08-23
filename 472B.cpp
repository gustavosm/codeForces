#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n, k;
	int c;
	int v[2005], f[2005];
	int ans;
	int acc;
	
	while (cin >> n >> k)
	{
		for (int i = 0 ; i < n ; ++i) cin >> v[i];
		c = 0;
		sort(v, v + n);
		
		for (int i = n - 1; i >= 0; i -= k)
		{
			acc = 0;
			for (int j = max(i - k + 1, 0) ; j <= i; ++j)
			{
				acc += v[j];
				
				if (j > max(i - k + 1, 0)) acc -= v[j - 1];
			}
			f[c++] = acc - 1;
		}
		ans = 0;
		for (int i = 0 ; i < c; ++i)
			ans += f[i];
		
		cout << (ans << 1) << '\n';
	}
}
