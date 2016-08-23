#include <bits/stdc++.h>

#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
using namespace std;
typedef pair<int, int> ii;


int main()
{
	vector<pair<int, int> > v;
	
	int n;
	
	int ans;
	int i;
	int x;
	int y;
	
	
	while(cin >> n)
	{
		ans = 0;
		f(i, n)
		{
			cin >> x >> y;
			v.pb(ii(x, y));
		}
		ans = min(2, n);
		
		for (int i = 1; i < n - 1; ++i)
		{
			if (v[i].first - v[i].second > v[i - 1].first)
				++ans;
			else if (v[i].first + v[i].second < v[i + 1].first)
				v[i].first += v[i].second, ++ans;
		}
		cout << ans << '\n';
		v.clear();
	}	
	
}
