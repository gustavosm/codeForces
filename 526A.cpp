#include <bits/stdc++.h>

using namespace std;
int main()
{
	char v[105];
	
	int n;
	int flag;
	
	while(cin >> n)
	{
		getchar();
		int inicio = -1;
		
		scanf("%s", v);
		
		int pulo = 1;
		
		flag = 0;
		while (pulo < n)
		{
			for (int i = 0 ; i < n; i++)
			{
				if (i + (pulo * 4) >= n) break;
				if (v[i] == '*' && v[i + pulo] == '*' && v[i + pulo*2] == '*' && v[i + pulo*3] == '*' && v[i + 4*pulo] == '*')
				{
					flag = 2;
					break;
				}
			}
			if (flag == 2) break;
			pulo++;
		}
		
		if (flag == 2) cout << "yes\n";
		else cout << "no\n";
	}	
}
