#include <bits/stdc++.h>


using namespace std;

typedef long long ll;


int main()
{
	int n, m;
	int a, b;
	ll ans = 0;
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++i)
	{
		for (int j = 0 ; j < m ; ++j)
		{
			cin >> a >> b;
			
			if (a || b) ++ans;
		}
	}
	
	cout << ans << '\n';
}
