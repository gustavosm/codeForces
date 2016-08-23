#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

int main()
{
	ll a, b, k;
	
	while (cin >> k >> a >> b)
	{
		if (a > 0 && b > 0)
			cout << (b / k) - (a - 1) / k << '\n';
		else if (a <= 0 && b >= 0)
			cout << (b / k) + 1 + (abs(a) / k) << '\n';
		else
			cout << abs(a) / k - (abs(b) - 1) / k << '\n';
	}
}
