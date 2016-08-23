#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n, r, avg;
	
	vector<pair<int, int > > v;
	ll a, b, sum;
	while (cin >> n >> r >> avg)
	{
		sum = 0;
		for (int i = 0 ;  i < n ; i++)
		{
			cin >> a >> b;
			sum += a;
			v.push_back(pair<int, int> (b, a));
		}
		if (sum / n >= avg) cout << "0\n";
		else
		{
			sort(v.begin(), v.end());
			
			ll ans = 0;
			
			for (int i = 0 ; i < n && (sum / n) < avg; i++)
			{
				ll diff = avg - (sum / n);
				ans += min((r - v[i].second), diff) * v[i].first; 
				sum += min((r - v[i].second), diff) * v[i].first;
			}
			
			cout << ans << '\n';
		}
		
		v.clear();
	}	
}
