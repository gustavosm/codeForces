#include <bits/stdc++.h>
 
 
using namespace std;
 
 
 
int main()
{
	int n;
	
	int x;
	int um;
	
	while (cin >> n)
	{
		um = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			if (x == 1) um = 1;
		}
		
		if (um) cout << "-1\n";
		else cout << "1\n";
	}
}
