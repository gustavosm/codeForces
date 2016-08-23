#include <bits/stdc++.h>


using namespace std;


int v[100010];


int main()
{
	int n;
	
	cin >> n;
	
	memset(v, 0, sizeof v);
	
	int i = 0;
	
	while (n--)
	{
		++v[i];
		if (i > 0)
		{
			while (i > 0 && v[i] == v[i - 1])
			{
				++v[i - 1];
				v[i] = 0;
				--i;
			}
		}
		++i;
	}
	
	for (int j = 0; j < i ; ++j)
		cout << v[j] << ' ';
	cout << '\n';
}
