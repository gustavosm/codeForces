#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int main()
{
	ll a, b, s;
	
	
	while (cin >> a >> b >> s)
	{
		if (s < (a + b)) cout << "No\n";
		else
		{
			if (((a + b) & 1) && (s & 1)) cout << "Yes\n";
			else if ((!(a + b) & 1) && !(s & 1)) cout << "Yes\n"; 
			else cout << "No\n";
		}
	}
}
