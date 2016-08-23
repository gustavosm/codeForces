#include <bits/stdc++.h>


#define PI M_PI
#define EPS 0.000000001

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector< ii > vii;

int main() 
{
	int n;
	int l[10005];
	int d[10005];
	
	map<int, int> m;
	map<int, int> m2;
	
	int sum = 0;
	int maior = INT_MIN;
	
	cin >> n;
	
	for (int i = 0 ; i < n ; i++)
	{
		cin >> l[i];
		if (maior < l[i]) maior = l[i];
	}
	for (int i = 0 ; i < n ; i++)
		if (maior == l[i]) ++sum;
	
	if (sum > n / 2) cout << "0\n";
	else
	{
		for (int i = 0 ; i < n ; i++)
		{
			cin >> d[i];
			++m2[l[i] * d[i]];
		}
		
		for (map<int, int> :: iterator it = m2.begin() + 1; it != m2.end(); ++it)
		{
			ans += it->first;
		}
	}
	
	
	
}
