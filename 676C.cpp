/*#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

int v[MAXN];

int calc(int n, int k) 
{
    int zeros = 0;
    int ones = 0;
    int rb = -1;
    int rf = -1;
    int rl = 0;
    int beg = -1;
    
    for(int i = 0; i < n; ++i) 
    {
        if(v[i]) ++ones;
        else ++zeros;
        while(zeros > k) 
        {
            ++beg;
            if(v[beg]) --ones;
            else --zeros;
        }
        if(zeros + ones >= rl) 
        {
            rb = beg;
            rf = i;
            rl = zeros + ones;
        }
    }

	return rl;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    string s;
 	
 	cin >> n >> k;
 	
 	cin >> s;
 	
 	memset(v, 0, sizeof v);
    for(int i = 0; i < n; ++i) 
    {
    	if (s[i] == 'a')
    		v[i] = 1;
    }
    int first = calc(n, k);
    
 	memset(v, 0, sizeof v);
    for(int i = 0; i < n; ++i) 
    {
    	if (s[i] == 'b')
    		v[i] = 1;
    }
    cout << max(first, calc(n, k)) << '\n';
}*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	string in;
	
	cin >> n >> k;
	cin >> in;
	
	int ans = 0;
	for (char a = 'a'; a <= 'b'; ++a)
	{
		int pointer_a = 0;
		int pointer_b = 0;
		int changes = 0;
		while (pointer_b < n)
		{
			if (in[pointer_b] != a) 
				++changes;
			
			while (changes > k)
			{
				if (in[pointer_a] != a) --changes;
				++pointer_a;
			}
			//cout << "Pointer 1 = " << pointer_a << " E " << "Pointer 2 = " << pointer_b << " com " << changes << '\n';
			ans = max(ans, pointer_b - pointer_a + 1);
			++pointer_b;
		}
	}
	cout << ans << '\n';
}
