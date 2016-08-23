#include <bits/stdc++.h>

using namespace std;


int c[1000005];
int sum[66000];
int cont;
int v[20];

vector<vector<int> > sub;

void subconjunto(int n)
{
	for (int i = 0 ; i < (1 << n) ; i++)
	{
		for (int j = 0 ; j < n; j++)
		{
			if (i & (1 << j))
				sub[i].push_back(v[j]), sum[i] += v[j];
		}
	}
}
 
int main()
{
	int n;
	int l;
	int r;
	int x;
	
	while(cin >> n >> l >> r >> x)
	{
		for (int i = 0 ; i < n; i++)
			cin >> v[i];
			
		int t = (1 << n);
		
		sub.assign(t, vector<int> ());
		for (int i = 0 ; i < t; i++) sum[i] = 0;
		int ans = 0;
		
		cont = 0;
		
		subconjunto(n);
		
		for (int i = 0; i < sub.size(); i++)
		{		
			if (sum[i] >= l && sum[i] <= r)
			{
				int u = *max_element(sub[i].begin(), sub[i].end());
				int v = *min_element(sub[i].begin(), sub[i].end());
				if (u - v >= x)
					ans++;
			}
		}
		cout << ans << '\n';
		
		sub.clear();
	}
	return 0;
}
