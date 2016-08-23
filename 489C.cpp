#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int m, s;
	
	cin >> m >> s;
	if (s == 0 && m > 1) cout << "-1 -1\n";
	else if (s == 0 && m == 1) cout << "0 0\n";
	else
	{
		string maior;
		int aux = s;
		int tam = 0;
		while (aux > 0 && tam < m)
		{
			if (aux <= 9) maior.push_back(aux + '0');
			else maior.push_back('9');
			aux -= min(aux, 9);
			++tam;
		}
		if (tam == m && aux > 0) cout << "-1 -1\n";
		else
		{
			while (tam < m)
			{
				maior.push_back('0');
				++tam;
			}
			string menor = maior;
			reverse(menor.begin(), menor.end());
			if (menor[0] == '0')
			{
				int flag = 0;
				for (int i = 1 ; i < tam; ++i)
				{
					if (menor[i] != '0')
					{
						--menor[i];
						++menor[0];
						flag = 1;
						break;
					}
				}
				if (!flag) cout << "-1 -1\n";
				else cout << menor << ' ' << maior << '\n';
			}
			else cout << menor << ' ' << maior << '\n';
		}
	}
}
