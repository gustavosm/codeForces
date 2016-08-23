#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pt[55];
ll t[55];

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int n;
	ll c;
	
	cin >> n >> c;
	
	for (int i = 0 ; i < n ; ++i)
		cin >> pt[i];
	for (int i = 0 ; i < n ; ++i)
		cin >> t[i];
	
	ll p1 = 0LL;
	
	ll time = 0LL;
	
	for (int i = 0 ; i < n ; ++i)
	{
		time += t[i];
		p1 += max(0LL, pt[i] - time * c);
	}
	ll p2 = 0LL;
	
	time = 0LL;
	
	for (int i = n - 1 ; i >= 0; --i)
	{
		time += t[i];
		p2 += max(0LL, pt[i] - time * c);
	}
	
	cout << (p1 > p2 ? "Limak\n" : (p1 < p2 ? "Radewoosh\n" : "Tie\n"));
}
