#include <bits/stdc++.h>
using namespace std;

typedef long long L;

#define MAXN 110

int n;
L mat[MAXN];

void gauss()
{
    for(int j = 0; j < n ; ++j)
    {
        for(int i = j; i < n; ++i)
        {
            if(mat[i] > mat[j])
                swap(mat[i], mat[j]);
        }

        for(int i = j + 1; i < n; ++i)
        	mat[i] = min(mat[i], mat[i] ^ mat[j]);
    }

}

int main() 
{
    L ans;
    while(cin >> n)
    {
    	for (int i = 0 ; i < n ; ++i)
    		cin >> mat[i];
    	
    	gauss();
    	
    	ans = 0;
    	
    	for (int i = 0 ; i < n ; ++i)
    		ans = max(ans, ans ^ mat[i]);
    	cout << ans << '\n';
    }

    return 0;
}
