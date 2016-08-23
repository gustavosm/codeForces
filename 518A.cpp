#include <bits/stdc++.h>


using namespace std;


int main()
{
	string s1;
	string s2;
	
	string aux;
	
	while(cin >> s1 >> s2)
	{
		aux = s1;
		for (int i = s1.size() - 1; i >= 0; i--)
		{
			if (s1[i] == 'z') continue;
			else
			{
				++s1[i];
				if (i != s1.size() - 1)
				{
					for (int j = i + 1; j < s1.size(); j++)
						s1[j] = 'a';
				}
				break;				
			}
		}
		if (aux < s1 && s1 < s2) cout << s1 << '\n';
		else cout << "No such string\n";
	}
}
