#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

int main()
{
	ll menor;
	ll maior;
	int n;
	ll v[5006];
	int cont;
	
	while(cin >> n)
	{
		cont = 0;
		menor = INT_MAX;
		for (int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
			if (menor > v[i]) menor = v[i];
		}
		
		for (int i = 0 ; i < n ; i++)
		{
			ll aux = menor;
			maior = INT_MIN;
			for (int j = 0 ; j < n ; j++)
			{
				if (v[j] == 0)
				{
					while (v[j] == 0)
					{
						++j;
						if (j == n) break;
					}
					--j;
					if (j != n - 1) cont += menor;
				}
				else
				{
					v[j] -= menor;
					if (v[j] && aux > v[j]) aux = v[j];
					if (maior < v[j]) maior = v[j];
				}
			}
			cont += menor;
			menor = aux;
			if (maior == 0) break;
		}
		cout << min(n, cont) << '\n';
	}
}
