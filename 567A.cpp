#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> ii;


int main()
{
	vi v;
	
	int n;
	int x;
	
	
	int mn;
	int mx;
	while (cin >> n)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0 ; i < n ;  ++i)
		{
			mn = INT_MAX;
			mx = INT_MIN;
			if (i > 0) mn = min(mn, abs(v[i] - v[i - 1]));
			if (i < n - 1) mn = min(mn, abs(v[i] - v[i + 1]));
			
			mx = max(abs(v[i] - v[0]), abs(v[i] - v[n - 1]));
			
			cout << mn << ' ' << mx << '\n';
		}
		v.clear();
	}	
}
