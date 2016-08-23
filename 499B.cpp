#include <bits/stdc++.h>


using namespace std;

map<string, string> m1, m2;
int main()
{
	string s1, s2;
	
	string aux;
	
	int n, m;
	
	cin >> n >> m;
	
	for (int i = 0; i < m ; ++i)
	{
		cin >> s1 >> s2;
		
		m1[s1] = s2;
		m2[s2] = s1;
	}
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> s1;
		if (i) cout << ' ';
		if (m1.count(s1))
		{
			aux = m1[s1];
			if (s1.size() > aux.size())
				cout << aux;
			else cout << s1;
		}
		if (m2.count(s1))
		{
			aux = m2[s1];
			if (s1.size() > aux.size())
				cout << aux;
			else cout << s1;
		}
	}
	cout << '\n';
}
