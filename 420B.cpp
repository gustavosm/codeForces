#include <bits/stdc++.h>


using namespace std;

set<int> ativo;
vector<int> ans;
char op[100005];
int val[100005];
int usado[100005];

int n, m;

void check(int x)
{
	for (int i = 0 ; i < m; ++i)
	{
		if (op[i] == '-')
		{
			ativo.erase(val[i]);
		}
		else ativo.insert(val[i]);
		
		if (ativo.size() && ativo.find(x) == ativo.end()) return;
	}
	ans.push_back(x);
}

int main()
{
	vector<int> num;
	while (cin >> n >> m)
	{
		int first = -1;
		memset(usado, 0, sizeof usado);
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> op[i] >> val[i];
			
			if (op[i] == '-' && !usado[val[i]])
			{
				first = i;
				num.push_back(val[i]);
			}
			usado[val[i]] = 1;
		}
		for (int i = 1; i <= n; ++i) if (!usado[i]) ans.push_back(i);
		
		if (first != -1)
		{
			for (int i = 0 ; i < num.size() ; ++i)
				ativo.insert(num[i]);
			check(val[first]);
		}
		else check(val[0]);
		
		sort(ans.begin(), ans.end());
		
		cout << ans.size() << '\n';
		for (int i = 0 ; i < ans.size(); ++i)
		{
			if (i) cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
		ativo.clear();
		num.clear();
		ans.clear();
		
	}
	
}
