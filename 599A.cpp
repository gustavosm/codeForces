#include <bits/stdc++.h>


using namespace std;;


typedef long long ll;

ll d1, d2, d3;
int main()
{
	cin >> d1 >> d2 >> d3;
	
	cout << min(2 * d1 + 2 * d2, min(d1 + d2 + d3, min(2 * d1 + 2 * d3, 2 * d2 + 2 * d3))) << '\n';
}
