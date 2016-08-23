#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
int main()
{
	pair<ll, ll> p1, p2;
	
	int n;
	
	ll a, b, c;
	
	int ans = 0;
	
	cin >> p1.first >> p1.second;
	
	cin >> p2.first >> p2.second;
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> a >> b >> c;
		
		int sa = ((a * p1.first + b * p1.second + c) > 0);
		int sb = ((a * p2.first + b * p2.second + c) > 0);
		
		ans += (sa != sb);
	}
	
	cout << ans << '\n';
}
