#include <bits/stdc++.h>


using namespace std;


int main()
{
	int v[200005];
	
	int n, w;
	
	while (cin >> n >> w)
	{
		for (int i = 0 ; i < 2 * n ; ++i)
			cin >> v[i];
		
		sort(v, v + 2 * n);
		
		int boy = min(v[n], 2 * v[0]);
		cout << setprecision(10) << min((double)boy * (double)n + (double)(boy * n) / 2.0, (double)w) << '\n';
	}
}
