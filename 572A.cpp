#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

ll a[100006], b[100006];
int main()
{
	ll na, nb;
	ll k, m;
	
	while (cin >> na >> nb)
	{
		cin >> k >> m;
		for (int i = 0 ; i < na; ++i) cin >> a[i];
		for (int i = 0 ; i < nb; ++i) cin >> b[i];
		
		if (a[k - 1] < b[nb - m]) cout << "YES\n";
		else cout << "NO\n";
	}	
}
