#include <bits/stdc++.h>


using namespace std;

typedef pair<int, int> ii;

int mdc(int a, int b)
{
	return (b == 0? a : mdc(b, a % b));
}
int main()
{
	map<ii, int> m;	
	int n;
	
	int x0, y0;
	int x, y;
	
	int tiro;
	while (cin >> n >> x0 >> y0)
	{
		tiro = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x >> y;
			x -= x0;
			y -= y0;
			int r = mdc(x, y);
			
			ii aux = ii((x / r), (y / r));
			if (!m.count(aux))
			{
				++tiro;
				++m[aux];
			}
		}
		
		cout << tiro << '\n';
		m.clear();
	}
}
