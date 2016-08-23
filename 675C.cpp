#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

int n;
map<ll, ll> freq;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	ll x, sum;
	sum = 0;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		sum += x;
		++freq[sum];
	}
	
	ll k = 0;
	
	for (map<ll, ll> :: iterator it = freq.begin(); it != freq.end(); ++it)
		k = max(k, it->second);
	cout << n - k << '\n';
}
