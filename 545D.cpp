#include <bits/stdc++.h>

#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
using namespace std;

int cmp(const void *a, const void* b)
{
	return (*(int *) a - (*(int *) b));
}
int main()
{

	int v[100005];
	
	int n;
	int acc;
	int qtde;
	int i;
	
	while(cin >> n)
	{
		acc = 0;
		qtde = 0;
		
		f(i, n)
		{
			cin >> v[i];
		}
		qsort(v, n, sizeof(int), cmp);
		
		f(i, n)
		{
			if (v[i] >= acc)
			{
				acc+= v[i];
				qtde++;
			}
		}
		
		cout << qtde << '\n';
		
	}
}
