#include <bits/stdc++.h>


using namespace std;
#define MOD 1000000007

typedef long long ll;

ll n;
int k;

ll pow10(int exp)
{
	ll n = 1;
	while (exp--)
		n = (n << 3) + (n << 1);//n = n * 10 -> n = n * (8 + 2) -> n = n * 8 + n * 2
		
	return n;
}
ll calc(ll a, ll b)
{
	ll num = (pow10(k) - 1) / a + (b != 0);
	
	ll bg = b * pow10(k - 1);
	ll end = bg + pow10(k - 1) - 1;
	
	ll ret = (end / a) - (bg / a);
	if (!(bg % a) && bg) ++ret;
	
	ret = num - ret;
	return ret;
}

int main () 
{    
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
    cin >> n >> k;
    
    ll a[n], b[n];
    
    n /= k;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
            
    for (int i = 0; i < n; i++) 
        cin >> b[i];
    
    ll ans = 1;
    
    for (int i = 0; i < n; ++i)
        ans = (ans % MOD * (calc(a[i], b[i]) % MOD)) % MOD;
      
    cout << ans << '\n';
}
