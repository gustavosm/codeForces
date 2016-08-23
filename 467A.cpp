#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int ans = 0;
	int n;
	int p;
	int q;
	
	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> p >> q;
		if (p <= q - 2) ans++;
	}
	cout << ans << '\n';
}
