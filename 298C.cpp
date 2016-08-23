#include <bits/stdc++.h>

using namespace std;

int main() 
{
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	int x = 0, y = 0;
	
	for (int i=0;i<n;i++)
		if (a[i] == '1') x++;
	
	for (int i=0;i<m;i++)
		if (b[i] == '1') y++;
	
	if (x & 1) x++;
	
	if (x >= y) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
