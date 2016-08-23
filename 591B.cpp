#include <bits/stdc++.h>


using namespace std;

string str;

char a, b;

int *v[26];
int nxt[26];
int n, m;

void imprime()
{
	for (int i = 0 ; i < 26; ++i)
	{
		for (int j = 0 ; j < nxt[i]; ++j)
			str[v[i][j]] = (i + 'a');
	}
	cout << str << '\n';
}
int main()
{	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	cin >> str;
	for (int i = 0 ; i < 26; ++i)
	{
		v[i] = (int *) malloc(sizeof(int) * (n + 1));
	}
	memset(nxt, 0, sizeof nxt);
	
	for (int i = 0 ; i < n; ++i)
	{	
		v[str[i] - 'a'][nxt[str[i] - 'a']] = i;
		++nxt[str[i] - 'a'];
	}
	
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> a >> b;
		
		int *aux = v[a - 'a'];
		v[a - 'a'] = v[b - 'a'];
		v[b - 'a'] = aux;
		swap(nxt[a - 'a'] , nxt[b - 'a']);
	}
	imprime();
}
