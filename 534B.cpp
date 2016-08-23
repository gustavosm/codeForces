#include <bits/stdc++.h>

using namespace std;

int main()
{
	int v1, v2;
	vector<int> vx;
	vector <int> vy;
	int ans;
	
	int t, d;
	
	while(cin >> v1 >> v2)
	{
		cin >> t >> d;
		ans = 0;
		int cont = 0;
		
		for (int i = v1; cont < t; i+= d, cont++)
			vx.push_back(i);
		
		cont = 0;
		for (int i = v2; cont < t; i+= d, cont++)
			vy.push_back(i);
		
		reverse(vy.begin(), vy.end());
		
		for (int i = 0; i < vx.size(); i++)
			ans+= min(vx[i], vy[i]);
		
		cout << ans << '\n';
		vx.clear();
		vy.clear();
	}
}
