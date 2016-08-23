#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ans;
vector<ll> v;
ll N;
int fatorial;

int rec(ll n, int i)
{
	if (n >= N)
	{
		return n == N;
	}
	else
	{
		if (v[i] == 3)
		{
			ans+= rec(n + 3, i + 1);
			ans+= rec(n + 6, i + 1);
			ans+= rec(n + 720, i + 1);
		}
		else
		{
			if (v[i] < 16)
			{
				ans+= rec(n + v[i], i + 1);
				ans+= rec(n + fat[v[i]], i + 1);
			}
			else
				ans+= rec(n + v[i], i + 1);
		}
	}
}

int main()
{
	
}
