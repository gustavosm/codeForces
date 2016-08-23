#include <bits/stdc++.h>
 
 
#define MAXN 100005
#define STMX 400005
using namespace std;
 
typedef long long ll;
ll v[MAXN];
ll st[STMX];
 
void init(int idx, int a, int b)
{
    if (a == b)
    {
        st[idx] = v[a];
    }
    else
    {
        int m = (a + b) / 2;
        init(idx * 2 + 1, a, m);
        init(idx * 2 + 2, m + 1, b);
        st[idx] = max(st[idx * 2 + 1],  st[idx * 2 + 2]);
    }
}
 
ll query(int idx, int a, int b, int i, int j)
{
    if (i > b || j < a) return -1;
     
    else if (j >= b && i <= a) return st[idx];
     
    int m = (a + b) / 2;
     
    ll x0 = query(idx * 2 + 1, a, m, i, j);
    ll x1 = query(idx * 2 + 2, m + 1, b, i , j);
     
    return max(x0, x1);
}
 
int main()
{
    int n;
    int qry;
    ios_base :: sync_with_stdio(0); cin.tie(0);
    char c;
    int x, y;
     
    cin >> n;
    
    for (int i = 0 ; i < n ; ++i) cin >> v[i];
     
    init(0, 0, n - 1);
     
    for (int i = 0 ; i < n ; ++i)
    {
    	ll mn = query(0, 0, n - 1, i + 1, n - 1);
    	if (v[i] > mn) cout << 0 << ' ';
    	else cout << mn - v[i] + 1 << ' ';
    }
    cout << '\n';
}
