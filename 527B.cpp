#include <bits/stdc++.h>

using namespace std;
int main ()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int m[26][26];
	int ans;
	char pos1;
	char pos2;
	char pos3;
	int posi;
	int k;
	int posj;
	int i;
	int j;
	int flag;
	string s1;
	string s2;
	
	int t;
	
	while(cin >> t)
	{
		cin >> s1 >> s2;
		
		memset(m, 0, sizeof m);
		int dist = 0;
		for (i = 0; i < t; i++)
		{
			if (s1[i] != s2[i])
			{
				m[s1[i]-'a'][s2[i]-'a'] = 1;
				++dist;
			}
		}
		pos3 = '1';
		pos1 = '1';
		pos2 = '1';
		flag = 0;
		for (i = 0 ; i < 26; ++i)
		{
			for (j = 0; j < 26; ++j)
			{
				if (m[i][j] == 1 && m[j][i] == 1)
				{
					pos1 = i + 'a';
					pos2 = j + 'a';
					flag = 2;
					break;
				}
				if (m[i][j] == 1)
				{
					for (k = 0; k < 26; ++k)
					{
						if (m[k][i] == 1)
						{
							pos1 = i + 'a';
							pos2 = j + 'a';
							pos3 = k + 'a';
							flag = 1;
						}
					}
				}
			}
			if (flag == 2) break;
		}
		if (!flag)
		{
				cout << dist << "\n-1 -1\n";
		}
		else
		{
			cout << dist - flag << '\n';
			if (flag == 2)
			{
				for (i = 0; i < t; ++i)
				{
					if (s1[i] == pos2 && s2[i] == pos1) posi = i;
					if (s1[i] == pos1 && s2[i] == pos2) posj = i;
				}
				cout << posi + 1 << " " << posj + 1<< '\n';
			}
			else
			{
				for (i = 0; i < t; ++i)
				{
					if (s1[i] == pos3 && s2[i] == pos1) posi = i;
					if (s1[i] == pos1 && s2[i] == pos2) posj = i;
				}
				cout << posi + 1<< " " << posj + 1<< '\n';
			}
		}
	}
}
