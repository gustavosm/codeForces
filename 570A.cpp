#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll v2[105];
	int n, m;
	int maior;
	while (cin >> n >> m)
	{
		memset(v2, 0, sizeof v2);
		
		int pos;
		int x;
		for(int i = 0 ; i < m ; ++i)
		{
			maior = INT_MIN;
			
			for (int j = 0 ; j < n; ++j)
			{
				cin >> x;
				if (x > maior)
				{
					maior = x;
					pos = j;
				}
			}
			
			++v2[pos];
		}
		
		int mx = *max_element(v2, v2 + n);
		
		for (int i = 0 ; i < n ; ++i)
		{
			if (v2[i] == mx)
			{
				pos = i;
				break;
			}
		}
		cout << pos + 1 << '\n';
	}
	
}
