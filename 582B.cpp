#include <bits/stdc++.h>


#define DIREITA
#define ESQUERDA
using namespace std;


int v[1005];
int n;

int main()
{
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> v[i];
	
	int need = 0;
	
	int direita = 1;
	int mudei = 0;
	int hacked = 0;
	int pos = 0;
	
	while (hacked < n)
	{
		if (direita)
		{
			for (int i = pos; i < n ; ++i)
			{
				if (need >= v[i])
				{
					++hacked;
					++need;
					pos = i;
					v[i] = INT_MAX;
				}
			}
			if (hacked < n)
				++mudei;
			direita = 0;
		}
		else
		{
			for (int i = pos; i >= 0; --i)
			{
				if (need >= v[i])
				{
					++hacked;
					++need;
					pos = i;
					v[i] = INT_MAX;
				}
			}
			if (hacked < n)
				++mudei;
			direita = 1;			
		}
	}
	cout << mudei << '\n';
	
}
