#include <bits/stdc++.h>

using namespace std;

int pal(string s)
{
	string a = s;
	
	reverse(a.begin(), a.end());
	return a == s;
}
int main()
{

	string s;
	string aux;
	int k;
	
	int inicio = 0;
	int fim;
	
	while(cin >> s)
	{
		cin >> k;
		int tam = s.size();
		if (tam % k != 0) cout << "NO\n";
		else
		{
			int var = s.size() / k;
			fim = var;
			int flag = 0;
			
			for (int i = 0 ; i < tam; i+= var)
			{
				aux.clear();
				for (int j = i; j < i + var; j++)
					aux.push_back(s[j]);
			
				if (!pal(aux))
				{
					flag = 1;
					break;
				}
			}
			if (flag) cout << "NO\n";
			else cout << "YES\n";		
		}
	}
}
