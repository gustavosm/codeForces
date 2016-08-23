#include <bits/stdc++.h>


using namespace std;

int main()
{
	int n;
	
	int m, c;
	m = c = 0;
	
	int u, v;
	
	cin >> n;
	
	while (n--)
	{
		cin >> u >> v;
		if (u > v) ++m;
		else if (v > u) ++c;
	}
	
	if (m > c) puts("Mishka");
	else if (c > m) puts("Chris");
	else puts("Friendship is magic!^^");
}
