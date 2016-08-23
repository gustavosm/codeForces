#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define INF 1e18
#define MAXN 31

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

L memo[MAXN][MAXN][MAXN + 25];

L dp(int m, int n, int k) {
    L &ans = memo[m][n][k];

    if(ans == -1) {
        if(k == 0 || n * m == k) ans = 0;
        else if(k > n*m) ans = INF;
        else {
            ans = INF;

            for(int i = 1; i < m; ++i) {
                for(int j = 0; j <= k; ++j) {
                    ans = min(ans, dp(i, n, j)
                              + dp( m - i, n, k - j)
                              + n * n);
                }
            }


            for(int i = 1; i < n; ++i) {
                for(int j = 0; j <= k; ++j) {
                    ans = min(ans, dp(i, n, j)
                              + dp( m, n - i, k - j)
                              + m * m);
                }
            }
        }
    }
    //  cout << n << ' ' << m << ' ' << k << ':' << ans << '\n';

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    memset(memo, -1, sizeof memo);
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << dp(n,m,k) << '\n';
    }
}
