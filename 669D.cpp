#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int pos[1000005];
int main()
{
	ios_base :: sync_with_stdio(0);
	
	int pos1;
	int pos2;
	int n, q;
	
	scanf("%d %d", &n, &q);
	
	int t, x;
	
	pos1 = 0;
	pos2 = 1;
	
	for (; q; --q)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d", &x);
			pos1 += x;
			pos2 += x;
			
			if (pos1 >= n) pos1 -= n;
			else if (pos1 < 0) pos1 += n;
			
			if (pos2 >= n) pos2 -= n;
			else if (pos2 < 0) pos2 += n;
			
		}
		else
		{
			if ((pos1 + 1 == pos2 && (pos2 & 1)) || (pos2 + 1 == pos1 && (pos1 & 1)))
				swap(pos1, pos2);
			else
			{
				if (pos1 & 1) --pos1;
				else ++pos1;
				
				if (pos2 & 1) --pos2;
				else ++pos2;
			}
		}
	}

	pos[pos1] = 1;
	pos[pos2] = 2;
	
	pos1 = (pos1 + 2) % n;
	int imp = 3;
	int p = 4;
	while (imp <= n)
	{
		pos[pos1] = imp;
		imp += 2;
		pos1 = (pos1 + 2);
		if (pos1 >= n) pos1 -=n;
	}
	pos2 = (pos2 + 2) % n;
	while (p <= n)
	{
		pos[pos2] = p;
		p += 2;
		pos2 = (pos2 + 2);
		if (pos2 >= n) pos2 -=n;
	}
	
	for (int i = 0; i < n ; ++i)
		printf("%d ", pos[i]);
	puts("");	
}
