#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int day;
	string of;
	string w;
	
	cin >> day >> of >> w;
	
	if (w == "month")
	{
		if (day <= 29) cout << 12 << '\n';
		else if (day <= 30) cout << 11 << '\n';
		else cout << 7 << '\n';
	}
	else if (day == 5 || day == 6) cout << 53 << '\n';
	else cout << 52 << '\n';
}
