#include <bits/stdc++.h>


using namespace std;

int main()
{
	int ans = 0;
	
	string s1, s2;
	int n;
	
	while(cin >> n)
	{
		
		cin >> s1;
		cin >> s2;
		
		for (int i = 0 ; i < n ; i++)
		{
			ans += min(abs(s1[i] - s2[i]), min(s1[i], s2[i]) + 10 - max(s1[i], s2[i])); 
		}
		cout << ans << '\n';
	}
}
