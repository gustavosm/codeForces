#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h1, a1, x1, y1;
	int h2, a2, x2, y2;
	int m;
	
	while(cin >> m)
	{
	
		cin >> h1 >> a1;
	
		cin >> x1 >> y1;
	
		cin >> h2 >> a2;
	
		cin >> x2 >> y2;
	
		int sec = 0;
		
		while(h1 != a1 || h2 != a2)
		{
			h1 = (x1 * h1 + y1) % m;
			h2 = (x2 * h2 + y2) % m;
			sec++;
	
			if (sec > 10000000)
				break;
		}

		if (sec > 10000000) cout << "-1\n";
		else cout << sec << '\n';
	}
}
