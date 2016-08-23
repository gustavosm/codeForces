#include <bits/stdc++.h>


using namespace std;


bool cmp1(int a, int b)
{
	return a < b;
}
bool cmp0(int a, int b)
{
	return a > b;
}


char s[100006];

int main()
{
	int n;
	int q;
	int i, j, k;
	
	while (scanf("%d %d", &n, &q) != EOF)
	{
		getchar();
		
		scanf("%[^\n]", s);
		
		while (q--)
		{
			scanf("%d %d %d", &i, &j, &k);
			--i;
			
			if (k) sort(s + i, s + j, cmp1);
			else sort(s + i, s + j, cmp0);
		}
		
		printf("%s\n", s);
	}
}
