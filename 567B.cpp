#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> ii;

int v[(int)(1e6 + 1)];

int main()
{
	int n;
	char op;
	int id;
	
	int tem, cap;
	
	while (cin >> n)
	{
		memset(v, 0, sizeof(v));
		tem = 0;
		cap = 0;
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> op >> id;
			
			if (op == '+')
			{
				++v[id];
				if (cap == tem)
					++cap;
					
				++tem;
			}
			else if (op == '-')
			{
				if (v[id])
				{
					v[id] = 0;
					--tem;
				}
				else ++cap;
			}
		}
		
		cout << cap << '\n';
	}
}
