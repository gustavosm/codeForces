#include <bits/stdc++.h>


using namespace std;

int main()
{
	string a, b;
	int n, t;
	
	cin >> n >> t;
	cin >> a;
	cin >> b;
	
	string ans;
	
	if (t == 0)
	{
		if (a == b) cout << a << '\n';
		else cout << -1 << '\n';
	}
	else
	{
		t = n - t;
		for (int i = 0 ; i < n; ++i)
		{
			
			if (a[i] == b[i] && t) ans.push_back(a[i]), --t;
			else ans.push_back('!');
		}
		int aindafalta1 = t;
		int aindafalta2 = t;
		
		for (int i = 0 ; i < n ; ++i)
		{
			if (a[i] != b[i])
			{
				if (aindafalta1) ans[i] = (a[i]), --aindafalta1;
				else if (aindafalta2) ans[i] = b[i], --aindafalta2;
			}
		}
		if (aindafalta1 || aindafalta2) cout << -1 << '\n';
		else
		{
			for (int i = 0 ; i < n ; ++i)
			{
				if (ans[i] == '!')
				{
					for (char l = 'a'; l <= 'z'; ++l)
					{
						if (l != a[i] && l != b[i])
						{
							ans[i] = l;
							break;
						}
					}
				}
			}
			cout << ans << '\n';
		}
	}
}
