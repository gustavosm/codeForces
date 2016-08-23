#include <bits/stdc++.h>

using namespace std;
char get(char c)
{
	return tolower(c);
}
int main ()
{
	int n;
	string s;
	map<char,int> m;
	
	cin >> n;
	getchar();
	getline(cin, s);
	
	if (n < 26) cout << "NO\n";
	else
	{
		for (int i = 0 ; i < n; i++)
			m[get(s[i])]++;
			
		cout <<	(m.size() == 26? "YES\n" : "NO\n");
		m.clear();
	}
}
