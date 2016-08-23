#include <bits/stdc++.h>


using namespace std;

int peso[505];
int used[505];
vector<int> ordem;
vector<int> aux;
vector<int> q;

int main()
{
	int n, m;
	
	int x;
		
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> peso[i];
	
	memset(used, 0, sizeof used);
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> x;
		ordem.push_back(x);
		if (!used[x])
		{
			used[x] = 1;
			q.push_back(x);
		}
	}
	int ans = 0;
	
	for (int i = 0 ; i < m ; ++i)
	{
		int cont = 0;
		int	j = 0;
		while (q[j] != ordem[i])
		{
			aux.push_back(q[j]);
			cont += peso[q[j] - 1];
			++j;
		}
		++j;
		while (j < q.size())
		{
			aux.push_back(q[j]);
			++j;
		}
		ans += cont;
		q.clear();
		q.push_back(ordem[i]);
		
		for (int i1 = 0 ; i1 < aux.size(); ++i1)
			q.push_back(aux[i1]);
			
		
		aux.clear();
	}
	
	cout << ans << '\n';
	
}
