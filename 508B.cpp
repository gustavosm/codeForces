#include <bits/stdc++.h>


using namespace std;
int pos;
int menor(string s)
{
	int ans = INT_MAX;
	int teste = s[s.size() - 1] - '0';
	
	for (int i = 0 ; i < s.size(); i++)
	{
		if (!((s[i] - '0') & 1))
		{
			ans = min(ans, s[i] - '0');
			pos = i;
			if (ans < teste) break;
		}
	}
	return ans;
}

int main()
{
	string s;
	
	cin >> s;
	
	int mn = menor(s);
	
	if (mn == INT_MAX) 
	{
		cout << "-1\n"; 
		return 0;
	}
	
	char aux = s[s.size() - 1];
	s[s.size() - 1] = s[pos];
	s[pos] = aux;
	
	cout << s << '\n';
	
}
