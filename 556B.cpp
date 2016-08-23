#include <bits/stdc++.h>


using namespace std;

int v[1005];
int n;
int ok()
{
	for (int i = 0 ; i < n; i++)
		if (v[i] != i) return 0;
	return 1;
}


int main()
{
	int cont = 0;
	while(cin >> n)
	{
		cont = 0;
		for (int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
		}
		
		while (!ok() && cont < 100000)
		{
			for (int i = 0 ; i < n ; i++)
			{
				if (i & 1) v[i] = (v[i] == 0 ? n - 1 : v[i] - 1);
				else v[i] = (v[i] + 1) % n;
			}
			++cont;
		}
		
		if (!ok()) cout << "No\n";
		else cout << "Yes\n";
	}
}

