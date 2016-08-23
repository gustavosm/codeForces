#include <bits/stdc++.h>


using namespace std;


int main()
{
	int a, b;
	
	
	cin >> a >> b;
	int win = 1;
	while (a > 0 && b > 0)
	{
		--b;
		--a;
		win ^= 1;
	}
	if (!win) cout << "Akshat\n";
	else cout << "Malvika\n";
}
