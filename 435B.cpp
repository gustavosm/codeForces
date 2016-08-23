#include <bits/stdc++.h>

using namespace std;

string num;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int k;
	cin >> num >> k;
	int n = num.size();
	for (int i = 0 ; i < n ; ++i)
	{
		char mx = num[i];
		int pos = 0;
		int flag = 0;
		for (int j = i + 1; j < n ; ++j)
		{
			if (mx < num[j] && (j - i) <= k)
			{
				mx = num[j];
				pos = j;
				flag = 1;
			}
		}
		if (flag)
		{
			k -= (pos - i);
			num = num.substr(0, i) + num[pos] + num.substr(i, pos - i) + num.substr(pos + 1);
		
			if (!k) break;
		}
	}
	cout << num << '\n';
}
