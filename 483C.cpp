#include <bits/stdc++.h>


#define MAXN 100006

using namespace std;

int v[MAXN];

int main()
{
	int n, k;
	
	cin >> n >> k;
	int cont = 0;
	int i, j;
	
	for (i = 1, j = n; i < j && k > 1; ++i, --j)
	{
		cout << j << ' ' << i << ' ';
		cont += 2;
		k -= 2;
	}
	if (cont < n)
	{
		if (!k)
			for (; cont < n; ++i, ++cont)
				cout << i << ' ';
		else
			for (; cont < n; --j, ++cont)
				cout << j << ' ';
	}
	cout << '\n';
	return 0;
}
