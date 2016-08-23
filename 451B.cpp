#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	
	int v[100004];
	
	int start, end;
	while (cin >> n)
	{
		start = -1;
		end = -1;
		for (int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
		}
		
		int flag = 1;
		for (int i  = 0 ; i < n - 1 ; ++i)
		{
			if (v[i] > v[i + 1])
			{
				if (start == -1) start = i;
				else end = i + 1;
			}
			else
			{
				if (start != -1 && end == -1) end = i;
			}
		}
		if (start == -1)
		{
			cout << "yes\n1 1\n";
			continue;
		}
		if (flag)
		{
			reverse(v + start, v + end + 1);
			for (int i = 0 ; i < n - 1 ; i++)
			{
				if (v[i] > v[i + 1])
				{
					flag = 0;
					break;
				}
			}
			if (flag) cout << "yes\n" << start + 1 << ' ' << end + 1 << '\n';
			else cout << "no\n";
		}
		else cout << "no\n";
	}
}
