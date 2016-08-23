#include <bits/stdc++.h>

using namespace std;
#define INF 99999999LL
#define pb push_back
#define mp make_pair
#define sz size

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpl;
typedef vector<vpl> vvpl;



pll div1, div2;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int n, m;

    cin >> n >> m;

    div2 = make_pair(1, 1);
    div1 = make_pair(n, n);
	
    for (int i = 0; i < m; ++i) 
    {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        
        if (a >= div1.first)
        {
        	cout << 0 << '\n';
        	return 0;
        }
		if (b <= div2.second)
		{
			cout << 0 << '\n';
			return 0;
		}
		
        div2.second = max(div2.second, a);
        div1.first = min(div1.first, b);
    }

	cout << div1.first - div2.second << '\n';
}
