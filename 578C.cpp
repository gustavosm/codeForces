#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

int main()
{
	
	ll a, b, c;
	
	cin >> a >> b;
	
	if (b > a) cout << -1 << '\n';
	else
	{
		cout << setprecision(10) << fixed << (double)(a + b) / (double)(2 * ((a + b) / (2 * b))) << '\n';
	}
	
	
	
	
}
