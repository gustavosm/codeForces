#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    int v1[102], v2[102];
    int i;
    int sum;
    int inicio;
    int sum2;
    vector<int> v;
    int flag;
    while(cin>>n>>k)
    {
        for (i = 0; i<n; i++)
        {
            cin>>v1[i];
        }
        for (i = 0; i<n; i++)
        {
            cin>>v2[i];
        }
        inicio = 0;
        flag = 0;
        while (inicio <= n - 1)
        {
            sum = 0;
            sum2 = 0;
            for (i=inicio; i<n; i++)
            {
                sum+=v1[i];
                sum2+=v2[i];
                if ((double)sum/(double)sum2 == (double)k)
                {
                    v.push_back(sum);
                    flag = 1;
                }
            }
            inicio++;
        }
        if (flag == 1)
            cout<<*max_element(v.begin(), v.end())<<'\n';
        else cout<<"-1\n";
        v.clear();
    }
    return 0;
}
