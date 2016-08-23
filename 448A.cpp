#include <bits/stdc++.h>

using namespace std;


int main()
{
	int a1, a2, a3;
	
	int b1, b2, b3;
	
	int n;
	
	
	while (cin >> a1 >> a2 >> a3)
	{
		cin >> b1 >> b2 >> b3;
	
		cin >> n;
	
		if ((((a1 + a2 + a3) + 4) / 5 + ((b1 + b2 + b3) + 9) / 10) <= n) cout << "YES\n";
		else cout << "NO\n";
	}
}
