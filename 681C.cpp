#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ;

PQ pq;

vector<ill> v;

string ans[] = {"insert", "getMin", "removeMin"};

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	string in;
	ll x;
	
	ll n;
	
	cin >> n;
	for (int i = 0 ; i < n; ++i)
	{
		cin >> in;
		if (in != ans[2])
		{
			cin >> x;
			if (in == ans[0])
			{
				v.push_back(ill(0, x));
				pq.push(x);
			}
			else
			{
				if (pq.empty() || pq.top() > x)
				{
					v.push_back(ill(0, x));
					v.push_back(ill(1, x));
					pq.push(x);
				}
				else
				{
					while (!pq.empty() && pq.top() < x)
					{	
						v.push_back(ill(2, pq.top()));
						pq.pop();						
					}
					if (pq.empty() || pq.top() != x)
					{
						v.push_back(ill(0, x));
						v.push_back(ill(1, x));
						pq.push(x);
					}
					else
						v.push_back(ill(1, x));
				}
			}
		}
		else
		{
			if (pq.empty())
				v.push_back(ill(0, 0LL)), pq.push(0LL);
				
			v.push_back(ill(2, -1LL));
			pq.pop();
		}
	}
	n = (int)v.size();
	cout << n << '\n';
	for (int i = 0 ; i < n; ++i)
	{
		if (v[i].first == 2) cout << ans[2] << '\n';
		else cout << ans[v[i].first] << ' ' << v[i].second << '\n';
	}
}
