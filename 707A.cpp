#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	char c;
	int n, m;
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++i)
	{
		for (int j = 0 ; j < m ; ++j)
		{
			cin >> c;
			
			if (c != 'B' && c != 'W' && c != 'G')
			{
				cout << "#Color\n";
				return 0;
			}
		}
	}
	cout << "#Black&White\n";
}
