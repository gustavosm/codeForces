#include <bits/stdc++.h>


#define pb push_back
using namespace std;

typedef long long ll;

int main()
{
	int v[105];
	
	int n;
	
	
	while (cin >> n)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> v[i];
		}
		int ans = 0;
		for (int i = 0 ; i < n ; ++i)
			ans += v[i] == 1;
			
		for (int i = 0 ; i < n ; ++i)
		{
			if (v[i] == 0)
			{
				if (i > 0 && i < n - 1)
					if (v[i - 1] == 1 && v[i + 1] == 1)
						++ans;				
			}
		}
		cout << ans << '\n';
			
	}
}
