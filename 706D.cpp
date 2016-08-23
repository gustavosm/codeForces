#include <bits/stdc++.h>

using namespace std;

typedef long long ss;

const int ROOT = 0;
const ss N = (ss)(1e5) * 2 + 5;
 
int tr[N * 33 + 1][2];
int acc[N * 33 + 1];

int curn;

void add(ss x)
{
	int curr = ROOT;
	++acc[curr];
	for (int i = 32; i >= 0; --i)
	{
		short bit = ((x >> i) & 1);
		if (!tr[curr][bit]) tr[curr][bit] = curn++;
		curr = tr[curr][bit];	
		++acc[curr];
	}
}

void rmv(ss x)
{
	int curr = ROOT;
	--acc[curr];
	for (int i = 32; i >= 0; --i)
	{
		short bit = ((x >> i) & 1);
		curr = tr[curr][bit];	
		--acc[curr];
	}
}

ss query(ss x)
{
	ss ans = 0;
	int curr = ROOT;
	for (int i = 32; i >= 0; --i)
	{
		short bit = ((x >> i) & 1);
		if (tr[curr][bit ^ 1] && acc[tr[curr][bit ^ 1]])
		{
			ans |= (1LL << i);
			curr = tr[curr][bit ^ 1];
		}
		else curr = tr[curr][bit];
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	memset(tr, 0, sizeof tr);
	memset(acc, 0, sizeof acc);
	char c;
	ss x;
	
	int n;
	
	cin >> n;
	curn = 1;
	
	add(0);
	while (n--)
	{
		cin >> c >> x;
		if (c == '+') add(x);
		else if (c == '-') rmv(x);
		else cout << query(x) << '\n';
	}
}


