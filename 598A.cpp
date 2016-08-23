#include <bits/stdc++.h>


using namespace std;

typedef long long ll;


int main()
{
	ll n;
	
	
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n;
		ll aux = n;
		n = ((1 + n) * n) / 2;
		ll pot = 1;
		
		for (; pot <= aux;)
		{
			n -= 2 * pot;
			pot *= 2;	
		}
		
		cout << n << '\n';
	}
}
