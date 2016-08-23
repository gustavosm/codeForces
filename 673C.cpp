#include <bits/stdc++.h>

using namespace std;

int v[5005];
int ans[5005];
int freq[5005];

int main()
{
	ios_base :: sync_with_stdio(0);
	
	int maxn = INT_MIN;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &v[i]);
	
	
	for (int i = 0 ; i < n; ++i)
	{
		memset(freq, 0, sizeof freq);
		maxn = INT_MIN;
		int pos;
		for (int j = i; j < n; ++j)
		{
			++freq[v[j]];
			if (freq[v[j]] > maxn)
			{
				maxn = freq[v[j]];
				pos = j;
			}
			else if (freq[v[j]] == maxn)
			{
				if (v[pos] >= v[j]) pos = j;
			}
			++ans[v[pos]];
		}
	}
	for (int i = 1 ; i <= n; ++i) printf("%d ", ans[i]);
	puts("");
}
