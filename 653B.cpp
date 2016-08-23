#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

ll ans;
vector<pair<string, string> > op;
vector<string> possiveis;
int n;
int m;

void monta(string a)
{
	if ((int)a.size() == n) possiveis.push_back(a);
	else
	{
		for (char c = 'a'; c <= 'f'; ++c)
			monta(a + c);
	}
}
void calc(string a)
{
	if (a == "a")
		++ans;
	else if ((int)a.size() == 1) return;
	
	for (int i = 0 ; i < (int)op.size(); ++i)
	{
		string &s = op[i].first;
		if (s[0] == a[0] && s[1] == a[1])
			calc(op[i].second + a.substr(2));
	}
}
string a, b;
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;	
	monta("");
	ans = 0;
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> a >> b;
		op.push_back(make_pair(a, b));
	}
	for (int i = 0 ; i < (int)possiveis.size(); ++i)
		calc(possiveis[i]);
	cout << ans << '\n';
}
