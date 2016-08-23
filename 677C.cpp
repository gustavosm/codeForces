#include <bits/stdc++.h>


using namespace std;
#define MOD 1000000007LL
typedef long long ll;

int value(char c)
{
	if (isdigit(c)) return c - '0';
	else if (isalpha(c) && c == toupper(c)) return c - 'A' + 10;
	else if (isalpha(c)) return c - 'a' + 36;
	if (c == '-') return 62;
	return 63;
}

int v[65];

string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVXWYZabcdefghijklmnopqrstuvxwyz-_";

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	string x;
	cin >> x;
	memset(v, 0, sizeof v);
	
	for (int i = 0 ; i < 64; ++i)
	{
		for (int j = 0 ; j < 64; ++j)
		{
			++v[value(s[i]) & value(s[j])];
		}
	}	
	ll ans = 1;
	
	for (int i = 0 ; i < (int)x.size(); ++i)
	{
		ans *= v[value(x[i])];
		ans %= MOD;
	}
	cout << ans << '\n';
}
