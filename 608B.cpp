#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define INF 9999999

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;

string a, b;
int freqa[2];
int freqb[2];

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b;
	
	
	for (int i = 0 ; i < a.size(); ++i)
		++freqa[a[i] - '0'];
	
	for (int i = 0 ; i < a.size(); ++i)
		++freqb[b[i] - '0'];
		
	int b = 0;
	int e = (int)a.size() - 1;
	
	while (e < b.size())
	{
		
	}	
}
