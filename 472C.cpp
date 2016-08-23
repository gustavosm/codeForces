#include <bits/stdc++.h>


using namespace std;


vector<pair<string, string> > v;
int order[100005];
int dp[100005][2];

int n;
int can(int pos, int second, int visited)
{
	if (visited == n) return 1;
	
	int &ans = dp[visited][second];
	if (ans == -1)
	{
		ans = 0;
		int next = order[visited];
		if (!second)
		{
			//cout << v[pos].first << ' ' << v[next].first << ' ' << v[next].second << '\n';
			//cout << (v[pos].first < v[next].first) << ' ' << (v[pos].first < v[next].second) << '\n';
			if (v[pos].first < v[next].first)
				ans = ans || can(next, 0, visited + 1);
			if (v[pos].first < v[next].second)
				ans = ans || can(next, 1, visited + 1);
		}
		else
		{
			//cout << v[pos].second << ' ' << v[next].first << ' ' << v[next].second << '\n';
			//cout << (v[pos].second < v[next].first) << ' ' << (v[pos].second < v[next].second) << '\n';
			if (v[pos].second < v[next].first)
				ans = ans || can(next, 0, visited + 1);
			if (v[pos].second < v[next].second)
				ans = ans || can(next, 1, visited + 1);
		}
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	string f, s;
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> f >> s;
		v.push_back(make_pair(f, s));
	}
	int x;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		--x;
		order[i] = x;
	}
	memset(dp, -1, sizeof dp);	
	if (can(order[0], 0, 1) || can(order[0], 1, 1)) cout << "YES\n";
	else cout << "NO\n";
}
