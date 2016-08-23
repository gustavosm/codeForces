#include <bits/stdc++.h>


using namespace std;


int main()
{
	map<int, int> s;
	
	vector<pair<int, pair<int, int> > > v;
	
	
	int n;
	int value;
	
	cin >> n;
	
	for (int i = 1; i < 2 * n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cin >> value;
			
			v.push_back(make_pair(value, make_pair(i, j)));
		}
	}
	
	sort(v.begin(), v.end());
	
	
	reverse(v.begin(), v.end());
	
	for (int i = 0 ; i < v.size(); ++i)
	{
		if (!s.count(v[i].second.first) && !s.count(v[i].second.second))
		{
			s[v[i].second.first] = v[i].second.second;
			s[v[i].second.second] = v[i].second.first;
		}
	}
	
	for (map<int, int> :: iterator it = s.begin(); it != s.end(); ++it)
		cout << (it->second + 1)<< ' ';
	cout << '\n';
}
