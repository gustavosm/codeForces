#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	ll a, b, c;
	
	
	cin >> a >> b >> c;
	
	if (!c)
	{
		if (a == b) cout << "YES\n";
		else cout << "NO\n";
	}
	else
	{
		if (c < 0 && a < b) cout << "NO\n";
		else if (c > 0 && a > b) cout << "NO\n";
		else if (c < 0 && a > b)
		{
			c = -c;
			if ((a - b) % c == 0) cout << "YES\n";
			else cout << "NO\n";
		}
		else
		{
			if ((b - a) % c == 0) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
