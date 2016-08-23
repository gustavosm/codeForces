#include <bits/stdc++.h>


using namespace std;

int main()
{
	int n;
	
	int cont = 1;
	
	cin >> n;
	
	for (int i = 1 ; i <= n; ++i)
	{
		for (int j = 0; j < (n - cont) / 2; ++j)
		{
			cout << '*';
		}
		for (int j = 0; j < cont; ++j) cout << 'D';
		
		for (int j = 0; j < (n - cont) / 2; ++j)
		{
			cout << '*';
		}
		if (i <= n / 2)
			cont += 2;
		else cont -= 2;
		
		cout << '\n';
	}
}
