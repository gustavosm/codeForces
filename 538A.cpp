#include <bits/stdc++.h>


using namespace std;


string solve(string s)
{
	size_t x = s.find("CODEFORCES");
	size_t y;
	
	if (x != string ::npos && (x == 0 || s.size() - 1 - x) return "YES\n";
	x = s.find("C");
	y = s.find("ODEFORCES");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 9 == s.size())) return "YES\n";
	x = s.find("CO");
	y = s.find("DEFORCES");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 8 == s.size())) return "YES\n";
	x = s.find("COD");
	y = s.find("EFORCES");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 7 == s.size())) return "YES\n";
	x = s.find("CODE");
	y = s.find("FORCES");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 6 == s.size())) return "YES\n";
	x = s.find("CODEF");
	y = s.find("ORCES");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 5 == s.size())) return "YES\n";
	x = s.find("CODEFO");
	y = s.find("RCES");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 4 == s.size())) return "YES\n";
	x = s.find("CODEFOR");
	y = s.find("CES");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 3 == s.size())) return "YES\n";
	x = s.find("CODEFORC");
	y = s.find("ES");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 2 == s.size())) return "YES\n";
	x = s.find("CODEFORCE");
	y = s.find("S");
	if (x != string::npos && y != string::npos && x < y && (x == 0 && y + 1 == s.size())) return "YES\n";
	if (x == 0 && s[s.size() - 1] == 'S') return "YES\n";

	return "NO\n";
}

int main()
{
	string s;
	
	while(cin >> s)
		cout << solve(s);
}
