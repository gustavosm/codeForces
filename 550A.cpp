#include <bits/stdc++.h>

using namespace std;


int contem(string s)
{
	int t = s.find("AB");
	
	if (t != string::npos)
	{
		s[t] = '-';
		s[t + 1] = '-';
		int x = s.find("BA");
		if (x == string::npos)
		{
			s[t] = 'A';
			s[t + 1] = 'B';
			
			x = s.find("BA");
			if (x == string::npos) return 0;
			
			s[x] = '-';
			s[x + 1] = '-';
			t = s.find("AB");
			if (t == string::npos) return 0;
			
			if (abs(t - x) > 1) return 1;
		}
		else if (t + 1 != x && x + 1 != t) return 1;
	}
	return 0;
}

int main()
{
	string s;
	
	while(getline(cin, s))
	{
		if (contem(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}
