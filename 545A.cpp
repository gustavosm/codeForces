#include <bits/stdc++.h>

#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
using namespace std;

int main()
{
	int a[105][105];
	
	int i;
	int j;
	int ans;
	vector<int> p;
	int flag;
	
	
	int n;
	
	while(cin >> n)
	{
		f(i, n)
		{
			f(j, n)
			{
				cin >> a[i][j];
			}
		}
		f(i, n)
		{
			flag = 0;
			f(j, n)
			{
				if (a[i][j] == 1 || a[i][j] == 3)
				{
					flag = 1;
					break;
				}
			}
			if (!flag) p.pb(i + 1);
		}
		
		cout << p.size() << '\n';
		f(i, p.size())
			cout << p[i] << ' ';
		cout << '\n';
		p.clear();
	}
}
