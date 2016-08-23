#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
multiset<ll> s;

ll gcd(ll a, ll b)
{
	return (b? gcd(b, a % b) : a);
}

int main()
{
	ll mdc[250005];
	
	int n;
	
	cin >> n;
	ll naux = n;
	n *= n;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> mdc[i];
	sort(mdc, mdc + n);
	vector<int> ans;
	
	for (int i = n - 1; i >= 0; --i)
	{
		multiset<ll> :: iterator it = s.find(mdc[i]); 
		if (it == s.end())
		{
			for (int j = 0 ; j < ans.size(); ++j)
			{
				ll g = gcd(mdc[i], ans[j]);
				s.insert(g);
				s.insert(g);
			}
			ans.push_back(mdc[i]);
		}
		else s.erase(it);
	}
	
	for (int i = 0 ; i < ans.size(); ++i)
	{
		if (i) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
}

