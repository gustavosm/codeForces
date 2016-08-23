#include <bits/stdc++.h>


using namespace std;


bitset<1005> prime;
vector<int> ps;
int n;

void find()
{
	prime.set();
	
	for (int i = 2; i <= n; ++i)
	{
		if (prime[i])
		{
			ps.push_back(i);
			
			for (int j = i * i; j <= n ; j += i)
				prime.reset(j);
		}
	}
}


int main()
{
	vector<int> ans;
	int aux;
	
	cin >> n;
	find();
	
	
	for (int i = 0; i < ps.size() ; ++i)
	{
		aux = 1;
		int x = ps[i];
		while (aux <= n / x)
		{
			aux *= x;
			ans.push_back(aux);
		}
	}
	cout << ans.size() << '\n';
	
	for (int i = 0; i < ans.size(); ++i)
		cout << (i? " " : "") << ans[i];
	cout << '\n';
	ans.clear();
	ps.clear();
}
