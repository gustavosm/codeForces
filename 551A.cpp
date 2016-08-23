#include <bits/stdc++.h>


using namespace std;


int main()
{
	int v[2004];
	
	int n;
	
	int x;
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		v[i] = x;
	}
	
	for (int i = 0 ; i < n ; ++i)
	{
		int p = 1;
		for (int j = 0 ; j < n ; ++j)
		{
			if (v[i] < v[j]) ++p;
		}
		
		cout << p << ' ';
	}
	cout << '\n';
}
