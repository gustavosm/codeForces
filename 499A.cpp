#include <bits/stdc++.h>


using namespace std;


typedef long long L;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int main()
{
	vii v;
	
	int n, m;
	int x, y;
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x >> y;
		
		v.push_back(make_pair(x, y));
	}
	
	int mn = 1;
	int ans = 0;
	
	for (int i = 0 ; i < n ; ++i)
	{
			mn += m * ((v[i].first - mn) / m);
		
		ans += v[i].first - mn;
		ans += v[i].second - v[i].first + 1;
		mn = v[i].second + 1;
	}
	cout << ans << '\n';
}
