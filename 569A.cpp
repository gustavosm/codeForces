#include <bits/stdc++.h>


using namespace std;


int main()
{
	int t, s, q;
	
	
	cin >> t >> s >> q;
	
	
	int ans = 0;
	
	while (s < t)
	{
		s += s * (q - 1);
		++ans;
	}
	cout << ans << '\n';
}
