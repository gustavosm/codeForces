#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n;
	
	int sum = 0;
	cin >> n;
	
	int i = 1;
	while (n > 0)
	{
		sum += i;
		if (n - sum < 0) break;
		n -= sum;
		++i;
	}
	cout << --i << '\n';
}
