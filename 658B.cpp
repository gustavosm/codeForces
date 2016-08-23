#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

set<pair<ll, int> > s;

ll v[150005];

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n, q;
	int k;
	int op;
	int id;
	
	cin >> n >> k >> q;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> v[i];
	
	while (q--)
	{
		cin >> op >> id;
		--id;
		
		if (op == 1) s.insert(make_pair(-v[id], id));
		else
		{
			int flag = 0;
			int x = 0;
			for (set<pair<ll, int> > :: iterator it = s.begin(); it != s.end() && x < k; ++it, ++x)
			{
				if ((*it).second == id)
				{
					cout << "YES\n";
					flag = 1;
					break;
				}
			}
			if (!flag) cout << "NO\n";
		}
	}
}
