#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;

int main()
{
	int v[55];
	int h[55];
	int x, y;
	

	int n;
	
	cin >> n;
	int days = 1;
	memset(v, 0, sizeof v);
	memset(h, 0, sizeof h);
	vl ans;
	for (int i = 0 ; i < n * n ; ++i)
	{
		cin >> x >> y;
		if (h[x] == 0 && v[y] == 0)
		{
			ans.push_back(days);
			h[x] = v[y] = 1;
		}
		++days;
	}
	for (int i = 0 ; i < ans.size(); ++i)
		cout << ans[i] << ' ';
		
	cout << '\n';
}
