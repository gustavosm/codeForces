#include <bits/stdc++.h>


using namespace std;


int main()
{
	int col[105] = {0};
	
	int n;
	int m;
	
	string v[105];
	
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> v[i];
	
	int ans = 0;

	for (int i = 0 ; i < m; ++i)
	{
		int flag = 0;
		for (int j = 0 ; j < n - 1; ++j)
		{
			if (v[j][i] > v[j + 1][i])
			{
				++ans;
				flag = 1;
				break;
			}
			else if (v[j][i] == v[j + 1][i])
				flag = 1;
		}
		if (!flag) break;
	}
	
	cout << min(ans, m - ans) << '\n';
}
