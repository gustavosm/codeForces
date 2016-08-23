#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;;


typedef long long ll;

ll a[MAXN], freq[MAXN], b[MAXN];

int n, m;
struct bob{
	ll val;
	int idx;
	
	bool operator < (const bob &other) const{
	
		return val < other.val;
	}
};

bob f[MAXN];

int bs(ll val)
{
	int b = 0;
	int e = n - 1;
	
	while (b <= e){
		int mid = (b + e) / 2;
		
		if (f[mid].val == val) return mid;
		
		if (f[mid].val > val)
			e = mid - 1;
		else b = mid + 1;
	}
	return -1;
}

int main()
{
	bool imp, multiple;
	memset(freq, 0, sizeof freq);
	
	
	multiple = false;
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++i)
	{
		ll x;
		cin >> x;
		f[i].val = x;
		f[i].idx = i;
		++freq[x];		
		
	}	
	for (int i = 0 ; i < m ; ++i)
		cin >> b[i];
	
	int i = 0;
	int pos;
	sort(f, f + n);
	for (int j = 0 ; j < m ; ++j)
	{
		pos = bs(b[j]);
		if (pos == -1)
			break;
			
		a[i++] = f[pos].idx + 1;
		if (freq[f[pos].val] >= 2) multiple = true;
	}
	if (pos == -1) cout << "Impossible\n";
	else
	{
		if (multiple) cout << "Ambiguity\n";
		else
		{		
			cout << "Possible\n";
			for (int i = 0 ; i < m ; ++i)
				cout << a[i] << ' ';
			cout << '\n';
		}
	}	
}
