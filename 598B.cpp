#include <bits/stdc++.h>



using namespace std;


int main()
{
	string s;
	string s2;
	int l, r, k, m;
	
	while (cin >> s)
	{
		cin >> m;
		
		while (m--)
		{
			cin >> l >> r >> k;
			--l, --r;
			
			k %= (r - l + 1);
			s2 = s;
			for (int i = l; i <= r; ++i)
			{
				int pos = i + k;
				if (pos > r) pos = l + pos - r - 1;
				
				s[pos] = s2[i];
			}	
		}
		cout << s << '\n';
	}
}
