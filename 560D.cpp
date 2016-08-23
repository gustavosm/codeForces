#include <bits/stdc++.h>



using namespace std;


string arruma(string s)
{
	int t = s.size();
	
	if (t & 1) return s;
	
	string x = arruma(s.substr(0, t / 2));
	string y = arruma(s.substr(t / 2));
	
	return (x < y ? x + y : y + x);
}

int main()
{
	string a, b;
	
	
	while (cin >> a >> b)
	{
		if (arruma(a) == arruma(b)) cout << "YES\n";
		else cout << "NO\n";
	}
}
