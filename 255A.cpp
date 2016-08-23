#include <bits/stdc++.h>


using namespace std;

string d[] = {"chest", "biceps", "back"};

int main()
{
	int n;
	int v[3];
	
	int x;
	
	while (cin >> n)
	{
		v[0] = v[1] = v[2] = 0;
		for (int i = 0; i < n ; ++i)
		{
			cin >> x;
			v[ i % 3 ] += x;
		}
	
		int *l = max_element(v, v + 3);
	
		cout << d[l - v] << '\n';
	}
}
