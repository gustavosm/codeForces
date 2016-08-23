#include <bits/stdc++.h>

#define PI acos(-1)
#define EPS 1e-9

using namespace std;

struct point{
	int x, y;
};

double dist(point &a, point &b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

int main()
{
	int n;
	double mn = INT_MAX * 1.0;
	double mx = INT_MIN * 1.0;
	
	point p1, p2;
	
	cin >> n >> p1.x >> p1.y;
	
	for (int i = 0; i < n ; ++i)
	{
		cin >> p2.x >> p2.y;
		
		double d = dist(p1, p2);
		if (mn - d > EPS) mn = d;
		if (mx - d < EPS) mx = d;
	}
	
	cout << setprecision(10) << fixed << ((mx * mx - mn * mn) * PI) << '\n';
}
