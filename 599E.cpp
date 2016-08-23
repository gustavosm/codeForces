#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >


const int inf = (1LL << 31) - 1;
const int mod = (ll) 1e9 + 7;

int n, m, q;
int a[111], b[111], c[111];
int A[111], B[111];
ll dp[15][1 << 14];

ll calc(int v, int mask)
{
    if ( mask == 0 ) return 1;

    ll &res = dp[v][mask];
    if ( res != -1 ) return res;
    res = 0;



    for (int i=0;i<q;i++){
        if ( a[i] == v && b[i] == v && c[i] != v) return 0;

        if ( (a[i] == v && (mask&(1<<b[i]))) && c[i] != v ){
            return res = 0;
        }
        if ( (b[i] == v && (mask&(1<<a[i]))) && c[i] != v ){
            return res = 0;
        }
    }


    int id = 0;
    for (int i=0;i<n;i++){
        if (mask&(1<<i) ){
            id = i;
            break;
        }
    }

    for (int s=mask;s>0;s=mask&(s-1)){
        if (s&(1<<id))
        for (int i=0;i<n;i++){
            if (s&(1<<i)){
                
                int t = mask^s;

                ll val2 = calc(v, t);
                ll val1 = calc(i, s^(1<<i));

                bool bad = false;
                for (int j=0;j<q;j++){
                    if ( c[j] == v){
                        if ( (s&(1<<a[j])) && (s&(1<<b[j]))){
                            bad = true;
                            break;                          
                        }
                    }
                    else {
                        if ( (s&(1<<a[j])) && (t&(1<<b[j])) ) bad = true;
                        if ( (t&(1<<a[j])) && (s&(1<<b[j])) ) bad = true;

                        if ( (s&(1<<c[j])) && (t&(1<<b[j])) ) bad = true;
                        if ( (t&(1<<c[j])) && (s&(1<<b[j])) ) bad = true;


                        if ( (s&(1<<c[j])) && (t&(1<<a[j])) ) bad = true;
                        if ( (t&(1<<c[j])) && (s&(1<<a[j])) ) bad = true;

                    }
                }


                for (int j=0;j<m;j++){
                    if ( (s&(1<<A[j])) && (t&(1<<B[j])) ) bad = true;
                    if ( (t&(1<<A[j])) && (s&(1<<B[j])) ) bad = true;
                    if ( A[j] == v && B[j] == i ) continue;
                    if ( B[j] == v && A[j] == i ) continue;
                    if ( A[j] == v && (s&(1<<B[j])) ) bad = true;
                    if ( B[j] == v && (s&(1<<A[j])) ) bad = true;
                }

                if (bad) continue;

                res += val1*val2;

            }
        }   
    }
    
    return res;
    
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif


    scanf("%d%d%d", &n, &m, &q);

    for (int i=0;i<m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        A[i] = u;
        B[i] = v;
    }

    for (int i=0;i<q;i++){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        a[i]--; b[i]--; c[i]--;
    }

    // check corner case

    memset(dp, -1, sizeof(dp));
    cout <<calc(0, ((1<<n)-1)^1)<<endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}
