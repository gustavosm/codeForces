#include <bits/stdc++.h>


using namespace std;


int main()
{
	vector<string> v;
	
	int n;
	int ans;
	string s;
	
	
	while(cin >> n)
	{
		for (int i = 0 ; i < n ; i++)
		{
			cin >> s;
			v.push_back(s);
		}
		int ans = 1;
		
		for (int i = 0 ; i < n ; i++)
		{
			int cont = 1;
			for (int j = i + 1 ; j < n ; j++)
			{
				if (v[i] == v[j]) cont++;
			}
			ans = max(ans, cont);
		}
		
		cout << ans << '\n';
		
		v.clear();
		
	}
}
