#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

typedef vector<ll> vi;

typedef pair<ll, ll> ii;

int main()
{
	int a, b, c, d, e;
	
	int n;
	
	cin >> n;
	
	int steps = 0;
	if (n >= 5)
	{
		steps += (n / 5);
		n %= 5;
	}
	if (n >= 4)
	{
		steps += (n / 4);
		n %= 4;
	}
	if (n >= 3)
	{
		steps += (n / 3);
		n %= 3;
	}
	if (n >= 2)
	{
		steps += (n / 2);
		n %= 2;
	}
	if (n >= 1)
		steps += n;
		
	cout << steps << '\n';
}
