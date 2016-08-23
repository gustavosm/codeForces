#include <bits/stdc++.h>


using namespace std;


int main()
{
	int v[30] = {0};
	
	int certo;
	
	string s1, s2;
	
	while(cin >> s1 >> s2)
	{
	
		certo = 0;
	
		if (s1.size() == s2.size())
		{
		
			sort(s1.begin(), s1.end());
			sort(s2.begin(), s2.end());
		
			if (s1 == s2) cout << "array\n";
			else cout << "need tree\n";
		}
		else
		{
			int flag = 0;
			for (int i = 0, j = 0; i < s1.size() && j < s2.size(); i++)
			{
				if (j < s2.size() && s1[i] == s2[j]) ++j;
				if (j == s2.size())
				{
					flag = 1;
					break;
				}
			}			
			if (flag) cout << "automaton\n";
			else
			{
				for (int i = 0 ; i < s1.size(); i++) ++v[s1[i] - 'a'];
				for (int j = 0 ; j < s2.size(); j++)
				{
					if (v[s2[j] - 'a'])
					{
						--v[s2[j] - 'a'];
						certo++;
					}
				}
				if (certo == s2.size())	cout << "both\n";
				else cout << "need tree\n";
			}
		}
	}
}
