#include <bits/stdc++.h>


using namespace std;


int main()
{	
	int v[3];
	
	int x, y;
	
	int n;
	
	FILE *f = fopen("input.txt", "r"), *f2 = fopen("output.txt", "w");
	
	fscanf(f, "%d", &n);
	v[0] = v[1] = v[2] = 0;
	if (n == 1) v[0] = 1;
	else if (n == 2) v[1] = 1;
	else v[2] = 1;
	
	for (int i = 0 ; i < 3; ++i)
	{
		fscanf(f, "%d %d", &x, &y);
		int aux = v[--x];
		v[x] = v[--y];
		v[y] = aux;
	}
	
	for (int i = 1; i <= 3; ++i)
	{
		if (v[i - 1] == 1)
		{
			fprintf(f2, "%d\n", i);
			break;
		}
	}
		
	
	
	
}
