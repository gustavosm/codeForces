#include <bits/stdc++.h>


using namespace std;


typedef long long ll;


set<ll> s;
vector<pair<int, int> > v;

int main()
{
	ios_base :: sync_with_stdio(0);
	int n;
	ll x;
	
	scanf("%d", &n);
	int comeco = 1;
	
	for (int i = 1; i <= n ; ++i)
	{
		scanf("%I64d", &x);
		if (s.count(x))
		{
			v.push_back(make_pair(comeco, i));
			s.clear();
			comeco = i + 1;
		}
		else s.insert(x);
	}
	int tam = (int)v.size();
	if (tam > 0)
	{
		v[tam - 1].second = n;
		printf("%d\n", (int)(v.size()));
		for (int i = 0 ; i < v.size(); ++i)
		{
			printf("%d %d\n", v[i].first, v[i].second);
		}
	}
	else printf("-1\n");
}
