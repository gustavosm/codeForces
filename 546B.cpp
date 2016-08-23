#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	map<int, int> m;
	int ans;
	int x;
	
	while(cin >> n)
	{
		for (int i = 0 ; i < n ; i++)
		{
			cin >> x;
			m[x]++;
		}
		ans = 0;
		for (map<int,int> :: iterator it = m.begin(); it != m.end(); it++)
		{
			int aux = it->first;
			
			while(m[aux] > 1)
			{
				m[aux]--;
				ans++;
				m[aux + 1]++;
			}
		}
		cout << ans << '\n';
		m.clear();
	}
}
