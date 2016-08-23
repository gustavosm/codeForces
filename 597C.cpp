#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXN 100100
#define MAXK 12

using namespace std;
typedef long long L;
typedef vector<L> vi;

#define LSOne(S) (S & (-S))
class FenwickTree {
private:
  vi ft;

public:
	FenwickTree() {}

	void init (int n) { ft.assign(n + 1, 0); }

	L rsq(int b) 
	{                                     
		L sum = 0; 
		for (; b; b -= LSOne(b)) sum += ft[b];	
		return sum;
	}
	L rsq(int a, int b) 
	{
		return rsq(b) - rsq(a - 1);
	}
	void adjust(int k, L v) 
	{
		for (; k < (int)ft.size(); k += LSOne(k)) 
			ft[k] += v; 
	}
};

int n, k;
int a[MAXN];

FenwickTree ft[MAXK];

L calc() 
{
    ++k;
    for(int i = 0; i <= k; ++i) 
    	ft[i].init(n + 1);
    
    ft[0].adjust(n + 1, 1);
    
    for(int i = n - 1; i >= 0; --i)
        for(int j = k; j >= 1; --j) 
            ft[j].adjust(a[i], ft[j - 1].rsq(a[i] + 1, n + 1));

    return ft[k].rsq(1, n);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n >> k) 
    {
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        
        cout << calc() << '\n';
    }
}
