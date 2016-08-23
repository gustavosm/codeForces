#include <bits/stdc++.h>



using namespace std;

int a[100005];
int f[100005];
int g[100005];

int main()
{
	int n;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> a[i];
	
	int ans = 1;
	f[0] = g[0] = 1;
	
	for (int i = 1 ; i < n ; ++i)
	{
		if (a[i] == a[i - 1]) 
		{
			f[i] = f[i - 1] + 1;
			g[i] = g[i - 1] + 1;
		} 
		else if (a[i] == a[i - 1] + 1) 
		{
			f[i] = 1;
			g[i] = f[i - 1] + 1;
		} 
		else
		{
			f[i] = g[i - 1] + 1;
			g[i] = 1;
		}
		ans = max(ans, f[i]);
		ans = max(ans, g[i]);
	}	
	cout << ans << '\n';
}
