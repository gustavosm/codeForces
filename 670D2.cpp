#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll p[100005], t[100005];
ll n;
ll k;

int ok(ll x)
{
    ll y = 0;
	ll aux = k;
    for (int i = 0; i < n; ++i)
    {
    	if ((t[i] + aux) / p[i] < x)
    		return 0;
    	if (p[i] * x > t[i])
    		aux -= p[i] * x - t[i];
    }
    return 1;
}

int main ()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll b = 0;
    ll e = 10000000000LL;

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }

    while (b < e - 1)
    {
        ll mid = (b + e) >> 1;
        if (ok(mid))
            b = mid;
        else
            e = mid;
    }
    cout << b << '\n';
}
