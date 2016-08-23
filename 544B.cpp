#include <bits/stdc++.h>

using namespace std;

int por(int n)
{
	if (n == 1) return 1;
	
	else return (n + por(n - 1)) - (!(n % 2));
}

int main()
{
	int areia = 1;
	
	
	int k, n;
	
	cin >> n >> k;
	if (k > por(n))
	{
		cout << "NO\n";
		return 0;	
	}
	
	cout << "YES\n";
	for (int i = 1 ; i <= n ; i++)
	{
		areia = i % 2;
		for (int j = 0 ; j < n ; j++)
		{
			if (k && areia) cout << 'L', --k;
			else cout << 'S';
			
			areia ^= 1;
			
		}
		cout << '\n';
	}
}
