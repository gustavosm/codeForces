#include <bits/stdc++.h>


using namespace std;


int main()
{
	int ans = -1;
	
	
	int n;
	int flag;
	int x;
	
	while (cin >> n)
	{
		ans = -1;
		flag = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			if (!flag)
			{
				while (x % 2 == 0) x /= 2;
				while (x % 3 == 0) x /= 3;	
			
				if (ans == -1) ans = x;
				else
				{
					if (ans != x)
					{
						cout << "No\n";
						flag = 1;
					}
				}
			}
		}
		if (!flag) cout << "Yes\n";
	}
}
