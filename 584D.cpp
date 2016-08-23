#include <bits/stdc++.h>
  
#define pb push_back
   
#define MAXN 30000010
#define gP(n)(prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n)(prime[n>>6]&=~(1<<((n>>1)&31)))
  
using namespace std;
     
typedef long long ll;
   
vector<ll> p;
unsigned int prime[MAXN];
   
void sieve()
{
    memset(prime, 1, sizeof(prime));
    p.pb(2);
    ll i;
    for (i = 3; i < MAXN; i += 2)
        if (prime[i])
        {
            p.pb(i);
            unsigned int i2 = i + i;
            for (register unsigned int j = i * i; j < MAXN; j += i2) prime[j] = 0;
        }
}
int primo(ll n)
{
	for(int i=0;i<p.size();++i)
    {
        while( n%p[i] == 0 )
        {
        	return 0;
        }
    }
    return 1;
}
int main()
{
	ll n;
	sieve();
	
	cin >> n;
	if (n == 3) cout << 1 << '\n' << 3 << '\n';
	else if (n == 5) cout << 2 << '\n' << 3 << ' ' << 2 << '\n';
	else
	{
		cout << 3 << '\n' << 3 << ' ';
		n -= 3;
		
		for (int i = 0 ; i < p.size(); ++i)
		{
			ll procura = n - p[i];
	
			if (binary_search(p.begin(), p.end(), procura))
			{
				cout << p[i] << ' ' << procura << '\n';
				return 0;
			}
			else if (primo(procura))
			{
				
				cout << p[i] << ' ' << procura << '\n';
				return 0;
			}
		}
	}
	return 0;
}
