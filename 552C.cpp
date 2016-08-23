#include <bits/stdc++.h>

using namespace std;


int main()
{
	long long m, w;
	
	while (cin >> w >> m)
	{
		for (int i = 0 ; i <= 100; i++)
		{
			if (!m) 
			{
				cout << "YES\n";
				break;
			}
			else if ((m - 1) % w == 0)
				m = (m - 1) / w;
			else if ( m % w == 0)
				m = m / w;
			else if ((m + 1) % w == 0)
				m = (m + 1) / w;
			else
			{
				cout << "NO\n";
				break;
			}
		}
	}
}
