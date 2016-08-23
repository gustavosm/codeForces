#include <bits/stdc++.h>


using namespace std;
typedef long long ll;


int main()
{
	int n;
	cin >> n;
	
	ll less = -1;
	ll x;
	
	ll tam = 0;
	ll ans = -1;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		
		if (x >= less)
		{
			++tam;
			less = x;
		}
		else
		{
			less = x;
			
			ans = max(ans, tam);
			tam = 1;
		}
	}
	
	ans = max(ans, tam);
	
	cout << ans << '\n';
}
