#include <bits/stdc++.h>

#define INF INT_MAX
#define mk make_pair
using namespace std;
typedef pair<int, int> ii;

vector<vector<char> > v;
int d[505][505];
int n, m;
bool ok;
const ii pos[] = { ii(-1, 0), ii( 0, -1), ii( 1, 0), ii(0, 1)};
inline bool adjacente(int r, int c, int a, int b)
{
	return (r == a + 1 && c == b) || (r == a - 1 && c == b) || (r == a  && c == b + 1) || (r == a && c == b - 1);
}
int valido(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}
bool dfs(int r1, int c1, int r2, int c2)
{
	for (int i = 0 ; i < 4; ++i)
	{
		int r3 = r1 + pos[i].first;
		int c3 = c1 + pos[i].second;
		if (r3 == r2 && c3 == c2) return true;
		
		if (valido(r3, c3) && v[r3][c3] == '.')
		{
			v[r3][c3] = '-';
			if (dfs(r3, c3, r2, c2)) return true;
		}
	}
	return false;
}

int main()
{
	int r1, c1, r2, c2;
	
	
	char c;
	
	while(cin >> n >> m)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			v.push_back(vector<char> ());
			for (int j = 0 ; j < m; ++j)
			{
				cin >> c;
				v[i].push_back(c);
			}
		}
		
		cin >> r1 >> c1 >> r2 >> c2;
		--r1; --c1; --r2; --c2;
		ok = false;
		if (r1 == r2 && c1 == c2)
		{
			int tem = 0;
			if (r1 > 0) if (v[r1 - 1][c1] != 'X') tem = 1;
			if (r1 < n - 1) if (v[r1 + 1][c1] != 'X') tem = 1;
			if (c1 > 0) if (v[r1][c1 - 1] != 'X') tem = 1;
			if (c1 < m - 1) if (v[r1][c1 + 1] != 'X') tem = 1;
			
			if (tem) cout << "YES\n";
			else cout << "NO\n";
		}
		else
		{
			if (adjacente(r1, c1, r2 , c2))
			{
				if (v[r2][c2] == 'X') cout << "YES\n";
				else
				{
					int tem = 0;
					if (r2 > 0) if (v[r2 - 1][c2] == '.') tem = 1;
					if (r2 < n - 1) if (v[r2 + 1][c2] == '.') tem = 1;
					if (c2 > 0) if (v[r2][c2 - 1] == '.') tem = 1;
					if (c2 < m - 1) if (v[r2][c2 + 1] == '.') tem = 1;
			
					if (tem) cout << "YES\n";
					else cout << "NO\n";					
				}
			}
			else
			{
				if (dfs(r1, c1, r2, c2)) 
				{
					int tem = 0;
					if (r2 > 0) if (v[r2 - 1][c2] != 'X') ++tem;
					if (r2 < n - 1) if (v[r2 + 1][c2] != 'X') ++tem;
					if (c2 > 0) if (v[r2][c2 - 1] != 'X') ++tem;
					if (c2 < m - 1) if (v[r2][c2 + 1] != 'X') ++tem;
					
					if (v[r2][c2] == 'X' && tem >= 1) cout << "YES\n";
					else if (v[r2][c2] != 'X' && tem >= 2) cout << "YES\n";
					else cout << "NO\n";					
				}
				else cout << "NO\n";
			}
		}
		v.clear();
	}
}
