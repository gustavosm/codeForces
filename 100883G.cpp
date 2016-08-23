#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

const ll MOD = 1000000007;

ll fat[20005]; //fatmod

void calc()
{
	fat[0] = 1LL;
	for (ll i = 1; i <= 20000; ++i)
	{
		fat[i] = (fat[i - 1] * i) % MOD; 
	}
}

ll mul_inv (ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0 , x1 = 1 ;
	if ( b == 1 ) return 1;
	while ( a > 1) 
	{
		q = a / b;
		t = b, b = a % b, a = t ;
		t = x0 , x0 = x1 - q * x0 , x1 = t ;
	}
	if ( x1 < 0 ) x1 += b0 ;
	return x1 ;
}

int main()
{
	ios_base :: sync_with_stdio(0);
	
	//cin.tie(0);
	calc();
	
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
	
		ll n, m;
	
		cin >> n >> m;
		
		ll ans = fat[ n + m ] * mul_inv(fat[n] * fat[m], MOD);
		cout << ans % MOD << '\n';
	}
}
