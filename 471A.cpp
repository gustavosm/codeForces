#include <bits/stdc++.h>


using namespace std;


int v[6];

int main()
{

	while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5])
	{
		sort(v ,v + 6);
		
		
		if (v[0] == v[3])
		{
			if (v[4] != v[5])
				cout << "Bear\n";
			else cout << "Elephant\n";
		}
		else if (v[1] == v[4])
		{
			if (v[0] != v[5])
				cout << "Bear\n";
			else cout << "Elephant\n";
		}
		else if (v[2] == v[5])
		{
			if (v[0] != v[1])
				cout << "Bear\n";
			else cout << "Elephant\n";
		}
		else cout << "Alien\n";
	}
}
