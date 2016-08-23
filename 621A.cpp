#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
int main()
{
	ll sum;
	
	int n;
	ll num;
	ll mn = INT_MAX;
	
	cin >> n;
	sum = 0;	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> num;
		sum += num;
		if (num & 1) mn = min(mn, num);
	}
	
	if (sum & 1) sum -= mn;
	cout << sum << '\n';
}
