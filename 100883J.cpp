#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll lim = 3000005;

bitset<lim> b;

vector<ll> palprimes;


string tobin(ll ans)
{
	string ret;
	
	while (ans)
	{
		ret.push_back((ans & 1) + '0');
		ans >>= 1;
	}
	
	reverse(ret.begin(), ret.end());
	return ret;
}

int palindrome(ll i)
{
	string s = tobin(i);
	
	string aux = s;
	reverse(aux.begin(), aux.end());
	
	return aux == s;
}

ll converte(string &bin)
{
	ll ans = 0;
	int t = (int)bin.size();
	
	for (int i = 0; i < t; ++i)
	{
		if (bin[i] == '1')
			ans |= (1LL << (t - 1 - i));
	}
	
	return ans;
}
void crivo()
{
	b.set();
	for (ll i = 2; i < lim; ++i)
	{
		if (b[i])
		{
			if (palindrome(i)) palprimes.push_back(i);
			
			for (ll j = i + i; j < lim; j += i)
				b.reset(j);
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	crivo();
	string in;
	
	while (cin >> in)
	{
		ll ok = converte(in);
		
		ll ans = (*upper_bound(palprimes.begin(), palprimes.end(), ok));
		
		cout << tobin(ans) << '\n';
	}
	
}

