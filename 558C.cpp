#include <bits/stdc++.h>


using namespace std;

int cnt[100005], visited[100005], ans[100005];

int main()
{
	int v;
	
	int n;
	
	queue<pair<int, int> > q;
	
	memset(visited, -1, sizeof visited);
	memset(ans, 0, sizeof ans);
	
	cin >> n;

	for (int i = 0 ; i < n ; ++i)
	{
		cin >> v;
		
		q.push(make_pair(0, v));
		
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second; q.pop();
			
			if (y > (int)1e5) continue;
			if (visited[y] == i) continue;
			
			visited[y] = i;
			ans[y] += x;
			++cnt[y]; 
			
			q.push(make_pair(x + 1, y >> 1));
			q.push(make_pair(x + 1, y << 1));
		}
	}
	
	int r = 100000000;
	for (int i = 0 ; i <= (int)1e5; ++i)
		if (cnt[i] == n) r = min(r, ans[i]);
	cout << r << '\n';
}
