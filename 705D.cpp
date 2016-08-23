#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define imprime(v) for(int X=0;X<v.size();X++) cout<<v[X]<<" "; cout<<endl;
#define grid(v) for(int X=0;X<v.size();X++){for(int Y=0;Y<v[X].size();Y++) cout<<v[X][Y]<<" ";cout<<endl;}
#define endl "\n"
const long long int  INF= 100000000000000LL;
const long double pi= acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector< vector< int > > vvi;
typedef vector< vector< ii > > vvii;
const int MOD=1e9+7;
int n,ini,fim;
int x[5005];
int a[5005];
int b[5005];
int c[5005];
int d[5005];
ll vaidir[5005];
ll vaiesq[5005];
ll vemdir[5005];
ll vemesq[5005];
ll dp[5005][5005];
int main()
{
    for(int i=0;i<5005;i++)
    {
        for(int j=0;j<5005;j++)
        {
            dp[i][j]=100000000000000000LL;
        }
    }
    sc3(n,ini,fim);
    for(int i=1;i<=n;i++) sc(x[i]);
    for(int i=1;i<=n;i++) sc(a[i]);
    for(int i=1;i<=n;i++) sc(b[i]);
    for(int i=1;i<=n;i++) sc(c[i]);
    for(int i=1;i<=n;i++) sc(d[i]);
    for(int i=1;i<=n;i++)
    {
        vaidir[i]=-x[i]+d[i];
        vaiesq[i]=x[i]+c[i];
        vemdir[i]=-x[i]+b[i];
        vemesq[i]=x[i]+a[i];
    }
    vemdir[ini]=0;
    vemesq[ini]=0;
    vaidir[fim]=0;
    vaiesq[fim]=0;
    /*cout<<"-------"<<endl;
    for(int i=1;i<=n;i++) cout<<vaidir[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<vaiesq[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<vemdir[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<vemesq[i]<<" ";
    cout<<endl;*/
    dp[1][1]=vaidir[1]+vemdir[1];
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==fim)
            {
                dp[i][j]=min(dp[i-1][j+1]+vemesq[i],dp[i-1][j]+vemdir[i]);
                continue;
            }
            if(i==ini)
            {
                dp[i][j]=min(dp[i-1][j-1]+vaidir[i],dp[i-1][j]+vaiesq[i]);
                continue;
            }
            dp[i][j]=min(dp[i][j],dp[i-1][j]+vemesq[i]+vaidir[i]);
            dp[i][j]=min(dp[i][j],dp[i-1][j+1]+vemesq[i]+vaiesq[i]);
            if(j>0) dp[i][j]=min(dp[i][j],min(dp[i-1][j]+vemdir[i]+vaiesq[i],dp[i-1][j-1]+vemdir[i]+vaidir[i]));
            //cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
        }
    }
    dp[n][0]=dp[n-1][1]+vemesq[n]+vaiesq[n];
    printf("%lld\n",dp[n][0]);
    return 0;
}
