#include <bits/stdc++.h>


using namespace std;


int main()
{
	int um;
	int zero;
	
	int n;
	
	string aux;
	
	
	while (cin >> n)
	{
		cin >> aux;
		um = zero = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			zero += aux[i] == '0';
			um += aux[i] == '1';
		}
		
		cout << abs(um - zero) << '\n';
	}

}
