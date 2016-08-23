#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n;
	
	cin >> n;
	
	if (n & 1) cout << 0 << '\n';
	else cout << n / 4 - (n % 4 == 0) << '\n';
}
