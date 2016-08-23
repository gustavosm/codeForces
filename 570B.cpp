#include <bits/stdc++.h>


using namespace std;

int main()
{
	int n, m;
	int a;
	while (cin >> n >> m)
	{
		if (n - m > ( m - 1)) a = m + 1;
		else a = m - 1;
		
		cout << (a == 0 ? 1 : a) << '\n';
	}
}
