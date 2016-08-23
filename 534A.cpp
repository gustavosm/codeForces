#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	vector<int> v;
	int i;
		
	while(cin >> n)
	{
		if (n <= 2) cout << "1\n1\n";
		else
		{
			if (n == 3) cout << "2\n1 3\n";
			else if (n == 4) cout << "4\n3 1 4 2\n";
			else
			{
				cout << n << '\n';
				for (int i = 1; i <= n; i+= 2)
				{
					if (i != 1) cout << ' ';
					cout << i;
				}
				for (int i = 2; i <= n; i+= 2)
					cout << ' ' << i;
				cout << '\n';
			}
		}
	}
}
