#include <bits/stdc++.h>


using namespace std;

int a[2000006] = {0};
int main()
{
	int x;
	int n;
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		a[x] = x;
	}
	
	for (int i = 0; i < 2000005; ++i)
		if (!a[i]) a[i] = a[i - 1];
		
	int ans = -12;
	for (int i = 1; i < 1000005; ++i)
	{
		if (a[i] == i)
		{
			for (int j = 2 * i - 1; j < 2000005; j += i)
			{
				ans = max(ans, a[j] % i);
			}
		}
	}
	cout << ans << '\n';
	
}
