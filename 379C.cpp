#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<int, ll> > v;


bool comp(pair<int, ll> a, pair<int, ll> b) 
{
	return a.second < b.second;
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n;
	int x;
	/*
	We can to sort ratings in nondecrease order, then iterate by them we can keep minimal rating not used before. If ai > cur, i's user recieve ai of rating and cur = ai + 1, else ai ≤ cur then i's user recieve cur of rating and cur increased by one.
	*/
	cin >> n;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		v.push_back(make_pair(i, x));
	}
	
	sort(v.begin(), v.end(), comp);
	
	int curr = v[0].second;
	
	for (int i = 0 ; i < n ; ++i)
	{
		if (v[i].second <= curr)
		{
			v[i].second = curr;
			++curr;
		}
		else
			curr = v[i].second + 1;
	}
	sort(v.begin(), v.end());
	
	for (int i = 0 ; i < n ; ++i)
		cout << v[i].second << ' ';
	cout << '\n';
}
