#include <bits/stdc++.h>

using namespace std;


int main()
{
	int v[10] = { 2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
	
	
	int x, y, z;
	
	while(cin >> z)
	{
		x = z / 10;
		y = z % 10;
		
		cout << v[x] * v[y] << '\n';
	}
}
