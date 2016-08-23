#include <bits/stdc++.h>


#define MAXN 1000007

using namespace std;


vector< vector<int> > m;
int freq[MAXN];


int main()
{
	ios_base :: sync_with_stdio(false);
	
	m.reserve(MAXN);
	int n;
	int x, pos, mx;
	int mxx;
	
	while (cin >> n)
	{
		
		for (int i = 0 ; i < MAXN; ++i) freq[i] = 0, m.push_back(vector<int>());
		
		mxx = mx = INT_MIN;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			if (x > mxx) mxx = x;
			
			++freq[x];
			if (mx < freq[x]) mx = freq[x];
			
			if (m[x].size() == 1) m[x].push_back(i);
			else if (m[x].size() == 2) m[x][1] = i;
			else m[x].push_back(i);
		}
		
		int tam = 100000000;
		int aux1, aux2, ans1, ans2;
		
		for (int i = 1 ; i <= mxx; ++i)
		{
			if (mx == freq[i]) 
			{
				vector<int> g = m[i];
				
				aux1 = g[0];
				aux2 = g[1];
				
				if (aux2 - aux1 + 1 < tam)
				{
					tam = aux2 - aux1 + 1;
					ans1 = aux1;
					ans2 = aux2;
				}
			}
		}
		
		cout << ans1 + 1 << ' ' << ans2 + 1 << '\n';
		
		m.clear();
		
	}
}

