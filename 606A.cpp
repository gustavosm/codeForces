#include <bits/stdc++.h>


using namespace std;


int main()
{

	int a, b, c;
	int x, y, z;
	
	cin >> a >> b >> c;
	cin >> x >> y >> z;
	
	if (a > x + 1)
	{
		while (b < y && a > x + 1)
		{
			++b;
			a -= 2;
		}
		while (c < z && a > x + 1)
		{
			++c;
			a -= 2;
		}		
	}
	if (b > y + 1)
	{
		while (a < x && b > y + 1)
		{
			++a;
			b -= 2;
		}
		while (c < z && b > y + 1)
		{
			++c;
			b -= 2;
		}		
	}
	if (c > z + 1)
	{
		while (b < y && c > z + 1)
		{
			++b;
			c -= 2;
		}
		while (a < x && c > z + 1)
		{
			++a;
			c -= 2;
		}		
	}
	
	if (a >= x && b >= y && c >= z) cout << "Yes\n";
	else cout << "No\n";
}
