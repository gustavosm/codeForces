#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

int main()
{
	
	int s1[26];
	vector<ll> sum;
	vector<int> p[100005];
	
	string s;
	int tot;
	
	map<ll, int> m[26];
		
	for (int i = 0 ; i < 26; i++)
	{
		cin >> s1[i];
	}
	cin >> s;
	
	sum.assign(s.size(), 0);
	
	for (int i = 0 ; i < s.size(); i++)
	{
		if (i)
			sum[i] = sum[i - 1] + s1[s[i] - 'a'];
		else sum[i] = s1[s[i] - 'a'];	
		
		p[s[i] - 'a'].push_back(i);		
	}
	ll ans = 0;
	for (int i = 0 ; i < 26; i++)
	{
		
		for (int j = 0; j < p[i].size(); j++)
		{
			int pos = p[i][j];
			ans += m[i][sum[pos - 1]];
			m[i][sum[pos]]++;
		}
		m[i].clear();
	}
	
	cout << ans << '\n';
	
	
}
