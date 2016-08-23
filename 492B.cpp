#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, l;
	
	double dist;
	vector<double> v;
	double x;
	
	while (cin >> n >> l)
	{
		for (int i = 0 ; i < n ; i++)
		{
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		
		dist = v[0];
		
		for (int i = 1; i < v.size(); i++)
		{
			double aux = (v[i] + v[i - 1]) / 2.;
			dist = max(dist, max(aux - v[i - 1], v[i] - aux));
		}
	
		double aux = (l - v[n - 1]);
		dist = max(dist, aux);
		
		cout << setprecision(10) << fixed << dist << '\n';
		
		v.clear();
	} 
}
