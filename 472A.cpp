#include <bits/stdc++.h>


using namespace std;


int prime(int n)
{
	int st = (int)sqrt(n);
	for (int i = 2 ; i <= st; ++i)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int n;
	
	
	while (cin >> n)
	{
		for (int i = 1; i < n ; ++i)
		{
			if (!prime(i) && !prime(n - i))
			{
				cout << i << ' ' << n - i << '\n';
				break;
			}
		}
	}
}
