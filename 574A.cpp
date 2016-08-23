#include <bits/stdc++.h>


using namespace std;


int main()
{
	int v[105];
	int n;
	priority_queue<int, vector<int>, less<int> > pq;
	cin >> n;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> v[i];
		if (i)
			pq.push(v[i]);
	}
	int votes = v[0];
	int ans = 0;
	while (1)
	{
		int u = pq.top();
		if (votes > u) break;
		pq.pop();
		--u;
		++votes;
		++ans;
		pq.push(u);
	}
	cout << ans << '\n';
}
