#include <bits/stdc++.h>


using namespace std;

int main()
{
	int testes;
	int vis[100005];
	long long a, m;
	
	cin >> a >> m;
	memset(vis, 0, sizeof vis);
	
	while (!vis[a % m] && a % m)
	{
		vis[a % m] = 1;
		
		a += a % m;
	}
	if (a % m == 0) cout << "Yes\n";
	else cout << "No\n";
}
