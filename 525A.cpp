#include <bits/stdc++.h>

using namespace std;
int main ()
{
	//ios_base :: sync_with_stdio(0);
	
	map<int, int> m;
	
	string s1;
	
	int n;
	int ans;
	
	cin >> n;
	getchar();
	
	cin >> s1;
	
		
	ans = 0;
	
	for (int i = 0 ; i < s1.size() ; i+= 2)
	{
		if (s1[i] - 'a' != s1[i + 1] - 'A')
		{
			if (m[s1[i + 1] - 'A'] == 0)
			{
				ans++;
			}
			else
			{
				m[s1[i + 1] - 'A']--;
			}
			m[s1[i] - 'a']++;
		}
	}
	cout << ans << '\n';
	m.clear();
}
