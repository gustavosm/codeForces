#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll P[200005], T[200005];
ll ans;
ll b[200005];
int n;
int w;

void kmpProcess()
{
	int i = 0;
	int j = -1;
	b[0] = -1;
	
	while (i < w)
	{
		while (j >= 0 && P[i] != P[j]) j = b[j];
		++i;
		++j;
		b[i] = j;
	}
}

void kmpSearch()
{
	int i = 0;
	int j = 0;
	while (i < n)
	{
		while (j >= 0 && T[i] != P[j]) j = b[j];
		++i;
		++j;
		if (j == w)
		{
			++ans;
			j = b[j];
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> w;
	if (w == 1)
	{
		cout << n << '\n';
		return 0;
	}
	ll x;
	ll y;
	cin >> x;
	--n; --w;
	for (int i = 0; i < n ; ++i)
	{
		cin >> y;
		T[i] = y - x;
		x = y;
	}
	cin >> x;
	for (int i = 0; i < w ; ++i)
	{
		cin >> y;
		P[i] = y - x;
		x = y;
	}
	
	ans = 0;
	kmpProcess();
	kmpSearch();
	cout << ans << '\n';
}

