#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll cnt1, cnt2, x, y;


bool ok(ll mid) 
{
    ll m1, m2;
    
    ll qtde1 = mid / x;
    ll qtde2 = mid / y;
    ll q = mid / (x * y);
    
    qtde1 -= q;
    qtde2 -= q;
    
    m1 = m2 = 0;
    if (cnt1 > qtde2) m1 = cnt1 - qtde2;
    if (cnt2 > qtde1) m2 = cnt2 - qtde1;

	return (mid - m1 - m2 - qtde1 - qtde2 - q >= 0);
}

int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
    cin >> cnt1 >> cnt2 >> x >> y;

    ll bgn = 1, ed = 1000000000000000000;
	while (bgn < ed)
	{
		ll mid = (bgn + ed) / 2;
		if (ok(mid)) ed = mid;
		else bgn = mid + 1;
	}
	
    cout << ed << '\n';
    return 0;
}
