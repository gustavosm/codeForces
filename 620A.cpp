#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

int main()
{
	ll x1, y1, x2, y2;
	
	
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		ll aux1 = abs(y1 - y2);
		ll aux2 = abs(x1 - x2);

		cout << max(aux1, aux2) << '\n';
	}
}
