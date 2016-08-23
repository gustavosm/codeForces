#include <bits/stdc++.h>



using namespace std;


int main()
{
	int v[55];
	
	int n, m;
	
	
	cin >> n >> m;
	
	for (int i = 0 ; i < m; ++i) cin >> v[i];
	
	sort(v, v + m);
	
	int aux = 0;
	int mn = 12314214;
	while (aux + n <= m)
	{
		mn = min(mn, v[aux + n - 1] - v[aux]);
		++aux;
	}
	cout << mn << '\n';
}
