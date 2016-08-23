#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tam;
	int ans;
	
	string s;
	
	while(getline(cin , s))
	{
		tam = s.size();
		ans = 0;
		for (int i = tam - 1; i >= 0; i--)
		{
			if (s[i] == '7') ans+= (int)(pow(2, tam - i - 1));
		}
		ans+= (int)(pow(2, tam)) - 1;
		
		cout << ans << '\n';
	}
}
