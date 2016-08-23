#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

vector<int> v;
vector<int> mins;

int main()
{
	int n;
	
	cin >> n;
	long long x;
	long long mn = INT_MAX;
	int pos;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> x;
		v.push_back(x);
		if (mn > x)
		{
			mins.clear();
			mins.push_back(i);
			mn = x;
		} else mins.push_back(i);
	}
	if (mins.size() == 1)
	{
		pos = mins[0];
	}
	else
	{
		ll mx = INT_MIN;
		int sz = mins.size();
		
		ll flag;
		for (int i = 0; i < sz; ++i)
		{
			int resto = (i + 1) % sz;
			
			if (resto == 0) flag = n - 1;
			else flag = 0;
			cout << mins[resto] << ' ' << mins[i] << '\n';
			cout << flag + mins[resto] - mins[i] + 1 << '\n';
			if (mx < flag + mins[resto] - mins[i] + 1)
			{
				mx = flag + mins[resto] - mins[i] + 1;
				pos = mins[i];
			}
		}	
		cout << mx << '\n';
	}
	long long ans = mn * n;
	pos = (pos + 1) % n;
	while (v[pos] > mn)
	{
		v[pos] -= mn;
		pos = (pos + 1) % n;
		++ans;	
	}
	
	cout << ans << '\n';
}
