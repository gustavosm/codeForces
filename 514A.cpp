#include <bits/stdc++.h>

using namespace std;
int main ()
{
	string s;
	int i;
	
	int inicio = 0;
	cin >> s;
	if (s[0] == '9') inicio = 1;
	
	for (i = inicio; i < s.size(); i++)
	{
		if (s[i] >= '5')
		{
			s[i] = '9' - s[i] + '0';
		}
	}
	
	cout << s << '\n'; 
}
