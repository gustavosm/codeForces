#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 100005;
const ll MAXB = 34;

ll mx;
class Trie
{
private:
	int trie[MAXN * MAXB][2];
	int pos;
public:
	void init()
	{
		pos = 0;
		memset(trie, -1, sizeof trie);
	}
	void insert(ll x)
	{
		int curr = 0;
		for (int i = 33; i >= 0; --i)
		{
			int b = 0;
			if (x & (1LL << i)) b = 1;
			if (trie[curr][b] == -1)
				trie[curr][b] = ++pos;
			curr = trie[curr][b];
		}
	}
	
	void query(int curr, ll x, int bit, ll ans)
	{
		if (bit == -1)
		{
			mx = max(mx, ans);
			return;
		}
		
		int b = 0;
		if (x & (1LL << bit)) b = 1;
		
		if (b == 0)
		{
			if (trie[curr][1] != -1)
				query(trie[curr][1], x, bit - 1, ans | (1LL << bit));
			else query(trie[curr][0], x, bit - 1, ans);
		}
		else
		{
			if (trie[curr][0] != -1)
				query(trie[curr][0], x, bit - 1, ans);
			else query(trie[curr][1], x, bit - 1, ans | (1LL << bit));
		}
	}
};

Trie t;
unordered_map<ll, ll> first_occ;

int main()
{
	int cases;
	ios_base :: sync_with_stdio(0); cin.tie(0);

	first_occ.reserve(MAXN);
	cin >> cases;
	
	while (cases--)
	{
		int n, q;
		first_occ.clear();
		t.init();
		cin >> n >> q;
		for (int i = 0 ; i < n ; ++i)
		{
			ll x;
			cin >> x;
			t.insert(x);
			if (!first_occ.count(x)) first_occ[x] = i + 1;
		}
		
		for (int i = 0 ; i < q ; ++i)
		{
			ll x;
			cin >> x;
			mx = -1;
			t.query(0, x, 33, 0);
			cout << first_occ[mx] << '\n';
		}
	}
}
