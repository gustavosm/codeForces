#include <bits/stdc++.h>


using namespace std;

int maxdist(int *v, int n)
{
	int ans = INT_MIN;
	
	for (int i = 0 ; i < n - 1; ++i)
	{
		if (v[i + 1] - v[i] > ans) ans = v[i + 1] - v[i];
	}
	return ans;
}
int main()
{
	int v[105];
	
	int n;
	
	while(cin >> n)
	{
	
		for (int i = 0 ; i < n ; ++i)
			cin >> v[i];

		int dist = INT_MAX;
		int aux = maxdist(v, n);
		for (int i = 1; i < n - 1; ++i)
		{
			if (dist > v[i + 1] - v[i - 1])
				dist = v[i + 1] - v[i - 1];
		}
		cout << max(dist, aux) << '\n';
	}
}
