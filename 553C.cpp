#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll comb[1005][1005];

void calc()
{
	comb[0][0] = 1;
	
	for (int i = 1 ; i <= 1002; i++)
	{
		comb[i][0] = 1;
		
		for (int j = 1; j <= i; j++)
		{
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % 1000000007;
		}
	}
}
int main()
{
	int k;
	ll tot;
	
	ll f = 1;
	
	ll v[1005];
	calc();
	while (cin >> k)
	{
		for (int i =  0 ; i < k; i++)
		{
			cin >> v[i];
		}
		
		f = 1;
		tot = 0;
		for (int i = 0 ; i < k ; i++)
		{
			f = (f * comb[tot + v[i] - 1][v[i] - 1]) % 1000000007;
			tot += v[i];
		}
		
		cout << f << '\n';
	}
}
