#include <bits/stdc++.h>

using namespace std;
int main()
{
	int v[1500];
	map<int, int> m;
	map<int, int> :: reverse_iterator it;
	int tot;
	int tot2;
	int qtde;
	int n;
	int ans;
	
	while(cin >> n)
	{
		qtde = (int) pow(2, n + 1) - 2;
		for (int i = 1; i <= qtde; i++)
		{
			cin >> v[i];
		}
		for (int i = 1; i <= qtde; i++)
		{
			tot = 0;
			tot2 = 0;	
			for (int j = i; j<= qtde; j+= 2*i)
			{
				tot+= v[j];
				if (j + 1 <= qtde) tot2+= v[j + 1];
			}
			m[tot]++;
			m[tot2]++;
		}
		it = m.rbegin();
		ans = 0;
		int maior = it->first;
		it++;
		for (; it != m.rend(); it++)
			ans+= maior - it->first;
		cout << ans << '\n';
		m.clear();
	}
}
