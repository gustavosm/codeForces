#include <bits/stdc++.h>

#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
using namespace std;

int dist(string s1, string s2)
{
	int i;
	int ans = 0;
	
	f(i, s1.size())
		if (s1[i] != s2[i]) ans++;	
	return ans;
}
int main()
{
	string s1;
	string s2;
	
	string ans;
	int i;
	int j;
	int p = 0;
	
	while (getline(cin, s1))
	{
		getline(cin, s2);;
		
		j = 0;
		f(i, s1.size())
		{
			if (s1[i] != s2[j])
			{
				if (p) ans.pb(s1[i]);
				else ans.pb(s2[j]);
				
				p^= 1;
			}
			else ans.pb(s2[j]);
			j++;
		}
		if (dist(s1, ans) == dist(s2, ans)) cout << ans << '\n';
		else cout << "impossible\n";
		
		ans.clear();
	}	
}
