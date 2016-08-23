#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long ll;

ll a, b;

ll ans;
void busca(ll at, int zeros)
{
	if (at > b) return;
	
	if (a <= at && at <= b && zeros == 1)
		++ans;
	
	if (!zeros) busca(at << 1, zeros + 1);
	
	busca((at << 1) + 1, zeros);
}

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	
	ans = 0;
	cin >> a >> b;
	busca(1, 0);
	
	cout << ans << '\n';
}
