#include <bits/stdc++.h>

using namespace std;

string in;

string a, b;

set<string> v;
int n;

void calc(int tam, string s, int i, int j)
{
	if (tam == n)
		v.insert(s);
	else
	{
		if (i < a.size())
		{
			string aux = s + a[i];
			calc(tam + 1, aux, i + 1, j);
		}
		if (j < b.size())
		{
			string aux = s + b[j];
			calc(tam + 1, aux, i, j + 1);
		}
	}
}
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> a >> b;
	
		n = (a.size() + b.size());
		
		calc(0, "", 0, 0);
		
		for (set<string> :: iterator it = v.begin(); it != v.end(); ++it)
			cout << (*it) << '\n';
		cout << '\n';
		v.clear();
	
		
	}
}
