#include <bits/stdc++.h>


using namespace std;


set<int> s;

int n, m;
int x;
int y;

int main()
{
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		for (int j = 0 ; j < x ; ++j)
		{
			cin >> y;
			s.insert(y);
		}
	}
	
	if ((int)s.size() == m)
		cout << "YES\n";
	else cout << "NO\n";
}
