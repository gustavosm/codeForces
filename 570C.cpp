#include  <bits/stdc++.h>

using namespace std;

string s;
char t = '.';
int n, m;

int num, group;

bitset<300005> ok;

int main()
{
	cin >> n >> m >> s;
	group = num = 0;
	
	ok.reset();
	
	for (int i = 0 ; i < n ; ++i)
	{
		if(s[i] == t)
		{
			num++;
			if(i == 0 || s[i - 1] != t)
				group++;
			ok.set(i + 1);
		}
	}
	for (int i = 0 ; i < m; ++i)
	{
		int d;
		char c;
		
		cin >> d >> c;
		
		bool a = ok[d], b = c == t;
		
		if(a != b)
		{
			if(a)
				--num;
				
			else ++num;
			
			if(ok[d - 1] && ok[d + 1] && !b)
				++group;

			if(ok[d - 1] && ok[d + 1] && b)
				--group;
			
			if(!ok[d - 1] && !ok[d + 1] && !b)
				--group;
			
			if(!ok[d - 1] && !ok[d + 1] && b)
				++group;
		}
		if (b) ok.set(d);
		else ok.reset(d);
		
		cout << num - group << '\n';
	}
}
