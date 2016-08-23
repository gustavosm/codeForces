#include <bits/stdc++.h>


using namespace std;


vector<string> v;

bool deu;

int n, k;
string s;
int trem(char c)
{
	return (c == toupper(c) && c != '.');
}

int soponto(int i, int j)
{
	for (int k1 = j + 1; k1 < n; ++k1)
	{
		if (trem(v[i][k1])) return 0;
	}
	return 1;
}

int dist(int i, int j)
{
	int ans = 0;
	
	while (j && !trem(v[i][j]))
	{
		--j;
		++ans;
	}
	return ans;
}

int val(int i, int j)
{
	return i >= 0 && i < 3 && j >= 0 && j < n;
}
void tenta(int i, int j)
{
	if (!val(i, j)) return;
	
	if (trem(v[i][j])) return;
	
	if (soponto(i, j))
	{
		deu = true;
		return;
	}
	if (j >= n)
	{
		deu = true;
		return;
	}
	if (deu) return;
	
	if (j + 1 < n - 1)
	{
		if (trem(v[i][j + 1]))
		{
			bool t1 = true, t2 = true;
			
			if (i - 1 >= 0)
				t1 = trem(v[i - 1][j]);
			if (i + 1 < 3)
				t2 = trem(v[i + 1][j]);
			
			if (t1 && t2) return;
			else if (!t1 && t2)
			{
				if (i + 1 < 3)
				{
					if (!(dist(i + 1, j) & 1))
					{
						tenta(i + 1, j)
						; if (deu) return;
					}
					else return;
				}
			}
			else if (!t2 && t1)
			{
				if (i - 1 >= 0)
				{
					if (!(dist(i - 1, j) & 1))
					{
						tenta(i - 1, j)
						; if (deu) return;
					}
					else return;
				}
			}
			else if (!t1 && !t2)
			{
				tenta(i - 1, j);
				if (deu) return;
				tenta(i + 1, j);
				if (deu) return;		
			}
		}
		else
		{
			tenta(i, j + 1);
			if (deu) return;
		}
	}
	else
	{
		if (trem(v[i][j + 1])) return;
		else
		{
			deu = true;
			return;		
		}
	}
	tenta(i + 1, j + 1);
	if (deu) return;
	tenta(i - 1, j + 1);
	if (deu) return;
	tenta(i, j + 1);
	if (deu) return;
}

int main()
{
	int cases;
	
	cin >> cases;
	int philip;
	
	while (cases--)
	{
		v.clear();
		cin >> n >> k;
		
		for (int i = 0 ; i < 3; ++i)
		{
			cin >> s;
			v.push_back(s);
			if (s[0] == 's') philip = i;
		}
		deu = true;
		
		for (int i = 0 ; i < n ; ++i)
		{
			if (trem(v[0][i]) && trem(v[1][i]) && trem(v[2][i]))
			{
				deu = false; 
				break;
			}
		}
		if (!deu) cout << "NO\n";
		else
		{
			deu = false;
			tenta(philip, 0);
			
			if (deu) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
