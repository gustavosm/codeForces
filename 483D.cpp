#include <bits/stdc++.h>


using namespace std;
#define INF INT_MAX

#define MAXN 100005

int st[4 * MAXN], lazy[4 * MAXN];
vector<pair<int, pair<int, int> > > cond;
int n;

void update(int pos, int i, int j, int l, int r, int val)
{
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		st[pos] |= val;
		lazy[pos] |= val;
		return;
	}
	
	st[pos << 1] |= lazy[pos];
	st[(pos << 1) + 1] |= lazy[pos];
	lazy[pos << 1] |= lazy[pos];
	lazy[(pos << 1) + 1] |= lazy[pos];
	
	lazy[pos] = 0;
	
	update(pos << 1, i, ((i + j) / 2), l, r, val);
	update((pos << 1) + 1, ((i + j) / 2) + 1, j, l, r, val);
	
	st[pos] = st[pos << 1] & st[(pos << 1) + 1];	
}

int randq(int p, int i, int j, int l, int r)
{
	if (i > r || j < l) return INF;
	if (i >= l && j <= r) return st[p];
	
	
    lazy[p << 1] |= lazy[p];
    lazy[(p << 1) + 1] |= lazy[p];
    st[p << 1] |= lazy[p];
    st[(p << 1) + 1] |= lazy[p];
    lazy[p] = 0;

    int p1 = randq(p << 1, i, ( i + j ) / 2, l , r);
    int p2 = randq((p << 1) + 1, (( i + j ) / 2 )+ 1, j, l , r);

    if(p1 == INF)
        return p2;
    if(p2 == INF)
        return p1;

    return (p1 & p2);
}


int main()
{
	int l, r, q;
	int m;
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	memset(lazy, 0, sizeof lazy);
	memset(st, 0, sizeof st);
	
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> l >> r >> q;
		--l, --r;
		
		cond.push_back(make_pair(q, make_pair(l , r)));
		
		update(1, 0, n - 1, l, r, q);
	}
	
	for (int i = 0 ; i < m ; ++i)
	{
		if (randq(1, 0, n - 1, cond[i].second.first, cond[i].second.second) != cond[i].first)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0 ; i < n ; ++i)
	{
		cout << randq(1, 0, n - 1, i , i) << ' ';
	}
	cout << '\n';
}
