#include <bits/stdc++.h>

#define sz size
using namespace std;

int hash(string s)
{
	int ans = 0;
	for (int i = 0 ; i < s.sz(); ++i)
		ans = (ans + (s[i] - 'a') * pow(26, i)) % 1000000007;
	return ans;
}


int main()
{
	int n, m;
	long long v[100005];
	string s;
	
	while (cin >> n >> m)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> s;
			v[i] = hash(s);
		}
		sort(v, v + n);
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> s;
			
			int h = hash(s);
			
			for (int i = 0; i < s.sz(); ++i)
			{
				if (s[i] == 'a')
				{
					if (v.count(h + 1) || v.count(h + 2))
					{
						cout << "YES\n";
						flag = 1;
						break;
					}
				}
				else if (s[i] == 'b')
				{
					if (v.count(h - 1) || v.count(h + 1))
					{
						cout << "YES\n";
						flag = 1;
						break;
					}
				}
				else if (s[i] == 'c')
				{
					if (v.count(h - 1) || v.count(h - 2))
					{
						cout << "YES\n";
						flag = 1;
						break;
					}
				}
			}
		}
	}
}
