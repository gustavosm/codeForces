#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int ans;
	int l, r;
	
	l = 0;
	r = 1;
	int x;
	ans = 1;
	cin >> n;
	cin >> x;
	int y = x;
	
	for (int i = 1 ; i < n ; ++i)
	{
		cin >> x;
		if (x <= y)
		{
			ans = max(ans, r - l);
			l = r;
		}
		++r;
		y = x;
	}
	ans = max(ans, r - l);
	cout << ans << '\n';
}
