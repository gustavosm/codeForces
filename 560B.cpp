#include <bits/stdc++.h>


using namespace std;

int main()
{
	int a1, b1, a2, b2, a3, b3;
	
	
	while (cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3)
	{
		if ((min(a2, b2) + min(a3, b3) <= min(a1, b1) && max(max(a2, b2), max(a3, b3)) <= max(a1, b1)) || 
			(min(a2, b2) + min(a3, b3) <= max(a1, b1) && max(max(a2, b2), max(a3, b3)) <= min(a1, b1))) cout << "YES\n";
		else if ((min(a2, b2) + max(a3, b3) <= min(a1, b1) && max(max(a2, b2), min(a3, b3)) <= max(a1, b1)) || 
			(min(a2, b2) + max(a3, b3) <= max(a1, b1) && max(max(a2, b2), min(a3, b3)) <= min(a1, b1))) cout << "YES\n";
		else if ((max(a2, b2) + min(a3, b3) <= min(a1, b1) && max(min(a2, b2), max(a3, b3)) <= max(a1, b1)) || 
			(max(a2, b2) + min(a3, b3) <= max(a1, b1) && max(min(a2, b2), max(a3, b3)) <= min(a1, b1))) cout << "YES\n";
		else if ((max(a2, b2) + max(a3, b3) <= max(a1, b1) && max(min(a2, b2), min(a3, b3)) <= min(a1, b1)) ||
				(max(a2, b2) + max(a3, b3) <= min(a1, b1) && max(min(a2, b2), min(a3, b3)) <= max(a1, b1))) cout << "YES\n";
				
		else cout << "NO\n";
	}
}
