#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;
   
const int N = 1000011;
   
ll p[N];
int prime_cont;
 
 
#define gP(n)(prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n)(prime[n>>6]&=~(1<<((n>>1)&31)))

unsigned int prime[100000010>>6];
     
void calc()
{
    memset(prime, -1, sizeof(prime));
    p[0] = 2;
    prime_cont = 1;
    for(ll i=3;prime_cont<1000010;i+=2)
    {
        if( gP(i))
        {
            p[prime_cont++] = i;
            ll foo = i+i;
            for(ll j=i*i;j<=15486023;j+=foo)rP(j);
        }
    }
   
}

ll ans(ll n)
{
	ll ret = 1;
	for(ll i=0;i<prime_cont;++i)
	{
		if (n % p[i] == 0) ret *= p[i];
		while(n%p[i] == 0 )
			n /= p[i];
		if( n == 1 ) break;
	}
	ret *= n;
	
	return ret;
}
int main()
{    
    int cases;
    int x;
     
    ll n;
    int flag;
    prime_cont = 0;
    calc();
    cin >> n;
    
    cout << ans(n) << '\n';
    
}
