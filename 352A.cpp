#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

int main()
{
	ll sum;
	ll zero;
	ll x;
	ll n;
	
	
	while (cin >> n)
	{
		sum = zero = 0;
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			
			if (x == 5) sum += x;
			else ++zero;
		}
		
		if (!zero) cout << -1 << '\n';
		else
		{
			while (sum % 9) sum -= 5;
			
			sum /= 5;
			
			if (!sum) cout << 0;
			else
			{
				for (int i = 0 ; i < sum; ++i)
					cout << 5;
				for (int i = 0 ; i < zero; ++i)
					cout << 0;
			}
			cout << '\n';
		}
	}
}
