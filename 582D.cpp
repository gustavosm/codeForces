#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

ll dp[105][105]; //estado: indice da lis e qntos seq posso pegar ainda
int n;
ll lis[105];
ll lis_aux[105];
ll v[105];
int p[105];


ll longest(int idx)
{
	if (idx == n) return 0;
	
	
	ll &ans = lis[idx];
	
	if (ans == -1)
	{
		ans = longest(idx + 1);
		for (int i = idx + 1; i < n ; ++i)
		{
			if (v[idx] < v[i])
			{
				ll ret = 1 + longest(i);
				if (ret > ans)
				{
					ans = ret;
					p[i] = idx;
				}
			}
		}
	}
	return ans;
}
ll monta(int i)
{
	int x = i;
	cout << "Seq do " << v[i] << '\n';
	while (1)
	{
		cout << v[x] << ' ';
		if (p[x] == -1) break;
		x = p[x];
	}
	cout << '\n';
	lis_aux[x] = v[i];
}

int main()
{
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> v[i];
	}
	memset(lis, -1, sizeof lis);
	memset(p, -1, sizeof p);
	for (int i = 0; i < n ; ++i)
	{
		memset(p, -1, sizeof p);
		longest(i);
		monta(i);
	}
	for (int i = 0 ; i < n ; ++i)
	{
		cout << "para a sequencia comecando em " << i << " tam = " << 1 + lis[i] << " o maior elemento eh " << lis_aux[i] << '\n';
	}
}


