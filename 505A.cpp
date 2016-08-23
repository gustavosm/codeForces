#include <bits/stdc++.h>

using namespace std;
int palindrome(string s)
{
	string aux = s;
	
	reverse(aux.begin(), aux.end());
	return aux == s;
}
int main()
{
	string s;
	while(cin >> s)
	{
	
		int flag;
		int size = s.size();
		flag = 0;
		for (int i = 0 ; i <= size; i++)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				string p;
				for (int j = 0; j < i; j++) p+= s[j];
				p+= c;
				for (int j = i; j < size; j++) p+= s[j];
				if (palindrome(p))
				{
					flag = 1;
					cout << p << '\n';
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) cout << "NA\n";
	}
}
