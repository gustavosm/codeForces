#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<int, vector<int> > m;
	map <int, vector<int> > :: reverse_iterator it;
	
	int n;
	cin >> n;
	int s;
	int r;
	int i = 1;
	while(n--)
	{
		cin >> s >> r;
		
		m[s+r].push_back(i);
		i++;
	}
	
	it = m.rbegin();
	
	sort(it->second.begin(), it->second.end());
	for (int i = 0; i < (it->second).size(); i++)
	{
		cout << (it->second)[i] << ' ';
	}
	cout << '\n';
	m.clear();
}
