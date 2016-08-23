#include <bits/stdc++.h>

using namespace std;

long long n;
long long v[200001];
long long pd[200001][11];
long long x;

long long func(int at, int k){
    if(at == n)
        return 0;

    if(pd[at][k] != -1)
        return pd[at][k];
    long long resp  = (v[at]|func(at+1,k));
    long long mul = v[at];
    for(int i = 1;i<=k;i++){
        mul*=x;
        resp = max(resp,mul|func(at+1,k-i));
    }


    return pd[at][k] = resp;;
}


int main() {

    long long k;
    cin >> n >> k >> x;
    long long maior = 0;

    for(int i = 0;i<n;i++){
    	cin >> v[i];
    }
    memset(pd,-1,sizeof pd);
    long long ans = -1;
    for(int i = n;i>=0;i--)
        ans = max(ans,func(i,k));
    cout<<ans<<endl;

    return 0;
}
