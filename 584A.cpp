#include <bits/stdc++.h>


using namespace std;

int len(int n)
{
	if (n <= 9) return 1;
	return 2;
}
int main()
{
	int n, t;
	
	
	cin >> n >> t;
	
	if (n == 1 && t <= 9) cout << t << '\n';
	else if (n == 1 && t >= 10) cout << -1 << '\n';
	else
	{
		cout << t;
		for (int i = len(t); i < n; ++i) cout << 0;
		cout << '\n';
	}

}
