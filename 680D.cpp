#include <bits/stdc++.h>


using namespace std;


typedef long long ll;
pair<ll, ll> ans;

inline ll pow3(ll num)
{
	return num * num * num;
}

ll calc(ll m, ll caixas, ll vol)
{
	if (m == 0)
		ans = max(ans, make_pair(caixas, vol));
	else
	{
		ll num = 1;
		while (pow3(num) <= m) {++num;}
		--num;
		
		calc(m - pow3(num), caixas + 1, vol + pow3(num));
		if (num - 1 >= 0)
			calc(pow3(num) - 1 - pow3(num - 1), caixas + 1, vol + pow3(num - 1));
	}		
}

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	
	ll m;
	cin >> m;

	ans = pair<ll, ll>(-1, -1);
	calc(m, 0, 0);
	cout << ans.first << ' ' << ans.second << '\n';	
}
