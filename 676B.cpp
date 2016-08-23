#include <bits/stdc++.h>

using namespace std;

typedef long double ll;

ll m[15][15];
int tot[15];
const ll EPS = numeric_limits<double>::epsilon();
const ll total = 10000000.0000;

void solve(ll soma, int linha, int col, int n)
{	
	if (n <= 0) return;
	
	if (fabs(m[linha][col] - total) < EPS)
		solve(soma / 2.0, linha + 1, col, n - 1), solve(soma / 2.0, linha + 1, col + 1, n - 1);
	else if (m[linha][col] + soma - total > EPS)
	{
		m[linha][col] = total;
		ll passa = m[linha][col] + soma - total;
		solve(passa / 2.0, linha + 1, col, n - 1);
		solve(passa / 2.0, linha + 1, col + 1, n - 1);
	}
	else m[linha][col] += soma;
}
int main()
{
	int n, time;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> time;
	tot[0] = 0;
	for (int i = 1; i <= n ; ++i) tot[i] = tot[i - 1] + i;
	
	memset(m, 0, sizeof m);
		
	if (time == 0) cout << 0 << '\n';
	else
	{
		int ans = 1;
		ll meio = (total / 2.0);
		for (int i = 2; i <= time; ++i)
			solve(meio, 1, 0, n - 1), solve(meio, 1, 1, n - 1);
		for (int i = 0 ; i <= 10; ++i)
		{
			for (int j = 0 ; j <= 10; ++j)
			{
				//cout << m[i][j] << ' ';
			
				if (fabs(m[i][j] - total) < EPS)
					++ans;
				
			} //cout << '\n';
		}
		cout << min(tot[n], ans) << '\n';
	}
}
