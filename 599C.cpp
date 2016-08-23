#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int v1[100005], v2[100005];


int main()
{
	int n;
	int x;
	cin >> n;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> v1[i];
		v2[i] = v1[i];
	}
	sort(v2, v2 + n);
	ll sum = 0;
	
	int blocks = 0;
	for (int i = 0 ; i < n ; ++i)
	{
		sum += v1[i] - v2[i];
		if (!sum) ++blocks;
	}
	cout << blocks << '\n';
}

/*#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;

typedef long long ll;

ll v[MAXN];
int idx[MAXN];
int n;

inline bool cmp(int i, int j) 
{
	return (v[i] != v[j] ? v[i] < v[j] : i < j);
}

int main() 
{
	while (cin >> n) 
	{
		for (int i = 0 ; i < n ; ++i) 
		{
			cin >> v[i];
			idx[i] = i;
		}
		sort(idx, idx + n, cmp);
		
		ll ans = 0;
		int mx = -1;
		for (int i = 0 ; i < n ; ++i)
		{
			int aux = idx[i];
			mx = max(mx, aux);
			if (mx == i) 
				++ans;
		}
		
		cout << ans << '\n';
	}
	return 0;
}*/
