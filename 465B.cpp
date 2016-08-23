#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n;
	vector<int> v;
	int op;
	int x;
	while (cin >> n)
	{
		op = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			
			if (x) v.push_back(i);
		}
		if (v.size() == 0) cout << 0 << '\n';
		else
		{
			op = 1;
			for (int i = 0 ; i < v.size() - 1; ++i)
			{
				int dist = v[i + 1] - v[i];
			
				if (dist > 1)
				{
					op += 2;
				}
				else ++op;
			}
		
			cout << op << '\n';
		}
		v.clear();
	}
}
