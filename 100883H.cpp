#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    ll c1, n1;
    ll c2, n2;
	bool troca;
    ios_base :: sync_with_stdio(0); cin.tie(0);

    while (cin >> n)
    {
        if (!n) return 0;
		troca = false;
        cin >> c1 >> n1 >> c2 >> n2;
        if ((double)c1 / (double)n1 > (double)c2 / (double)n2) swap(n1, n2), troca = true;
        
        ll times = n / n1;
        while (times > 0 && (n - times * n1) % n2 > 0)
        {
            --times;
        }
        if (times == 0  || (n - times * n1) < 0)
        {
        	times = n / n2;
            while (times > 0 && (n - times * n2) % n1 > 0)
            {
                --times;
            }
            if (times == 0 || (n - times * n2) < 0) cout << "failed\n";
            else
            {
            	if (!troca)
	                cout << (n - times * n2) / n1 << ' ' << times << '\n';
	            else cout << times << ' ' << (n - times * n2) / n1 << '\n';
            }
        }
        else
        {
        	if (troca)
                cout << (n - times * n1) / n2 << ' ' << times << '\n';
            else cout << times << ' ' << (n - times * n1) / n2 << '\n';
        }
    }
}
