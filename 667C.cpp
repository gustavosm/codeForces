#include <bits/stdc++.h>

using namespace std;

set<string> s;
set<string> estados[10005];

int main()
{
	string in;
	
	cin >> in;
	
	int n = in.length();
	if (n == 5 || n == 6) cout << 0 << '\n';
	else
	{
		for (int i = n - 1; i >= 5; --i)
		{
			string x = in.substr(i, 1);
			for (int j = i - 1; j >= i - 2 && j >= 5; --j)
			{
				x = in[j] + x;
				
				if ((estados[i + 1].size() == 1 && !estados[i + 1].count(x)) || estados[i + 1].size() > 1 || i + 1 >= n)	
				{
					estados[j].insert(x);
					s.insert(x);
				}
			}
		}
			
		cout << s.size() << '\n';
		for (set<string> :: iterator it = s.begin(); it != s.end(); ++it)
			cout << (*it) << '\n';
	}
}
