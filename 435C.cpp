#include <bits/stdc++.h>


using namespace std;

char g[1005][1005];

int v[1005];

int main()
{
	int n;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	int sum = 0;
	int mx = -1;
	
	for (int i = 0 ; i < 1005; ++i) for (int j = 0 ; j < 1005; ++j) g[i][j] = ' ';
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	int i;
	for (i = 0 ; i < n ; ++i)
	{
		if (v[i] == mx) break;
		sum += v[i];
	}
	int j = i;
	int subir = !(j & 1);
	int aux = sum;
	int l = 0;
	if (subir) l = mx - 1;
	
	for (; j < n; ++j)
	{
		char c = '\\';
		int passo = 1;
		if (subir) c = '/', passo = -1;
		int val = v[j];
		
		while (val--)
		{
			g[l][sum] = c;
			l += passo;
			++sum;
		}
		l += (-passo);
		subir ^= 1;
	}
	int tot = sum;
	sum = aux - 1;
	j = i - 1;
	subir = !(j & 1);
	l = mx - 1;
	if (subir) l = 0;
	for (; j >= 0; --j)
	{
		char c = '\\';
		int passo = -1;
		if (subir) c = '/', passo = 1;
		int val = v[j];
		
		while (val--)
		{
			g[l][sum] = c;
			l += passo;
			--sum;
		}
		l += (-passo);
		subir ^= 1;
	}
	for (int i = 0 ; i < mx; ++i) g[i][tot] = '\0';
	
	for (int i = 0 ; i < mx; ++i) cout << g[i] << '\n';
}
