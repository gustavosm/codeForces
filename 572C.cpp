#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int l;
int forma(int a, int b, int c)
{
	return (abs(a - b) < c && c < a + b) && (abs(a - c) < b && b < a + c) && (abs(b - c) < a && a < b + c);
}

int calc(int a, int b, int c)
{
	if (a > l || b > l || c > l) return 0;
	
	int ans = 0;
	if (forma(a + 1, b, c))
		ans += 1 + calc(a + 1, b, c);
	else if (forma(a, b + 1, c))
		ans += 1 + calc(a, b + 1, c);
	else if (forma(a, b, c + 1))
		ans += 1 + calc(a, b, c + 1);
	else if (forma(a + 1, b + 1, c))
		ans += 1 + calc(a + 1, b + 1, c);
	else if (forma(a + 1, b, c + 1))
		ans += 1 + calc(a + 1, b, c + 1);
	else if (forma(a + 1, b + 1, c + 1))
		ans += 1 + calc(a + 1, b + 1, c + 1);
		
	return ans;
}

int main()
{
	int a, b, c;

	while (cin >> a >> b >> c >> l)
	{
		cout << (forma(a, b, c)? 1 : 0) + calc(a, b, c) << '\n';
		
	}
}
