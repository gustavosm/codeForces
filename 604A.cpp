#include <bits/stdc++.h>


using namespace std;


int main()
{
	double ans = 0;
	int v[5];
	int x, w;
	
	for (int i = 0 ; i < 5; ++i)
	{
		cin >> v[i];
	}
	
	for (int i = 1 ; i <= 5; ++i)
	{
		cin >> w;
		x = 500 * i;
		ans += max((0.3 * x), (1.0 - v[i - 1] / 250.) * x - 50. * w);		
	}
	int hi, hs;
	
	cin >> hi >> hs;
	
	ans += 100. * hi - 50. * hs;
	
	printf("%.0lf\n", ans);
}
