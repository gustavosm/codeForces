#include <bits/stdc++.h>

using namespace std;


int main()
{
	int a;
	int b;
	int ans;
	
	ans = 0;
	cin >> a >> b;
	
	while(1)
	{
		if (a < 1 || b < 1) break;
		
		if (a + b < 3) break;
		
		if (a > b)
		{
			a -= 2;
			--b;
			ans++;
		}
		else
		{
			b -= 2;
			--a;
			ans++;
		}
	}
	cout << ans << '\n';
}
