#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll v[100005];

int main()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> v[i];
		if (i) v[i] += v[i - 1];
	}
	int q;
	cin >> q;
	while (q--)
	{
		int qtd;
		cin >> qtd;
		ll *pt = lower_bound(v, v + n, qtd);
		cout << distance(v, pt) + 1 << '\n';
	}
}
