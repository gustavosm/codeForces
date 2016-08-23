#include <bits/stdc++.h>


using namespace std;


int main()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq2;
	priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq1;
	
	
	int n;
	int x, y;
	
	while (cin >> n)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x >> y;
			
			if (x < 0) pq1.push(make_pair(x, y));
			else pq2.push(make_pair(x, y));	
		}
		int ans = 0;
		while (!pq1.empty() && !pq2.empty())
		{
			ans += pq1.top().second;
			ans += pq2.top().second;
			
			pq1.pop();
			pq2.pop();
		}
		
		if (pq1.empty() && !pq2.empty()) ans += pq2.top().second;
		else if (!pq1.empty() && pq2.empty()) ans += pq1.top().second;
		cout << ans << '\n';
		
		while (!pq1.empty()) pq1.pop();
		while (!pq2.empty()) pq2.pop();
	}
}
