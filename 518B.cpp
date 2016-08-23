#include <bits/stdc++.h>

using namespace std;


int main()
{
	int m1[255] = {0};
	
	char c;
	
	int yay;
	int whoops;
	
	int tem[300000];
	string s1;
	string s2;
	
	getline(cin, s1);
	getline(cin, s2);
	yay = 0;
	whoops = 0;
	for (int i = 0 ; i < s2.size(); i++)
	{
		m1[s2[i]]++;
	}
	for (int i = 0 ; i < s1.size(); i++)
	{
		tem[i] = 0;
		int & mapa = m1[s1[i]];
		if (mapa)
		{
			--mapa;
			++yay;
			tem[i] = 1;
		}
	}
	for (int i = 0 ; i < s1.size(); i++)
	{
		if (!tem[i])
		{
			char c = s1[i];
			if (islower(c)) c = toupper(c);
			else c = tolower(c);
			int & mapa = m1[c];
			if (mapa)
			{
				--mapa;
				++whoops;
			}
		}
	}
	printf("%d %d\n", yay, whoops);

}
