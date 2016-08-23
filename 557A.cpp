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
	int v[3] = {0,0,0};
	
	
	int n;
	int sum = 0;
	int v2[3][2];
	
	cin >> n;
	
	for (int i = 0 ; i < 3 ; i++)
	{
		cin >> v2[i][0] >> v2[i][1];
		
		v[i] = v2[i][0];
		sum += v[i];
	}
	for (int i = 0 ; i < 3 && n; ++i)
	{
		if (sum < n)
		{
			sum -= v[i];
			v[i] = min(v2[i][1], n - sum);
			sum += v[i];
		}
	}
	for (int i = 0 ; i < 3 ; i++)
		cout << v[i] << ' ';
	cout << '\n';
	
	return 0;
}
	
