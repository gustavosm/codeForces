#include <bits/stdc++.h>


using namespace std;

int a[55], b[55], c[55];



int main()
{
	int n;
	
	cin >> n;
	--n;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> a[i];
		
	for (int i = 0 ; i < n ; ++i)
		cin >> b[i];
		
	for (int i = 0 ;  i < n + 1; ++i)
		cin >> c[i];
		
	int ans = INT_MAX;
	int n_pode = -1;
	
	for (int i = n; i >= 0; --i)
	{
		int s = c[i];
		for (int j = i; j < n ; ++j)
			s += b[j];
		for (int j = i - 1; j >= 0; --j)
			s += a[j];
			
		if (s < ans)
		{
			ans = s;
			n_pode = i;
		}
	}
	int ans1 = INT_MAX;
	for (int i = 0; i < n + 1; ++i)
	{
		if (i == n_pode) continue;
		int s = c[i];
		
		for (int j = 0; j < i; ++j)
			s += a[j];
		for (int j = i; j < n ; ++j)
			s += b[j];
		
		ans1 = min(ans1, s);
	}
	
	cout << ans + ans1 << '\n';
}
