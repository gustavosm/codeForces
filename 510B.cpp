#include <bits/stdc++.h>

#define pb push_back
using namespace std;
int **adj;
vector<int> visited;
int n;
int m;
bool ciclo;
int pai;

void dfs(int filho, int p)
{
	visited[filho] = 1;
	for (int i = 0 ; i < n*m; i++)
	{
		if (adj[filho][i] > 0)
		{
			if (ciclo) break;
			if (i == pai && p != pai)
			{
				ciclo = true;
				break;
			}
			if (!visited[i])
				dfs(i, filho);
		}
	}
}
int main ()
{
	vector<string> v;
	
	string s;
	
	
	cin >> n >> m;
	getchar();
	
	adj = (int **) malloc(n*m*sizeof(int *));
	for (int i = 0 ; i < n*m ;i++)
	{
		adj[i] = (int *) calloc(n*m, sizeof(int));
	}
	for (int i = 0 ; i < n; i++)
	{
		getline(cin , s);
		v.pb(s);
	}
	for (int i = 0 ;i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j < m - 1)
			{
				if (v[i][j] == v[i][j+1])
				{
					cout << "Aresta de " << m*i+j << " para " << m*i+j+1 << '\n';
					adj[m*i + j][m*i + j + 1]++;
				}
			}
			if (j > 0)
			{
				if (v[i][j] == v[i][j-1])
				{
					cout << "Aresta de " << m*i+j << " para " << m*i+j-1 << '\n';
					adj[m*i + j][m*i + j - 1]++;
				}
			}
			if (i < n - 1)
			{
				if (v[i][j] == v[i+1][j])
				{
					cout << "Aresta de " << m*i+j << " para " << m*(i+1)+j << '\n';
					adj[m*i + j][m*(i+1) + j]++;
				}
			}
			if (i > 0)
			{
				if (v[i][j] == v[i-1][j])
				{
					cout << "Aresta de " << m*i+j << " para " << m*(i-1)+j << '\n';
					adj[m*i + j][m*(i-1) + j]++;
				}
			}
		}
	}
	visited.assign(n*m,0);
	ciclo = false;
	for (int i = 0 ; i < n*m; i++)
	{
		if (!visited[i])
		{
			pai = i;
			dfs(i,i);
			if (ciclo) break;
		}
	}
	if (ciclo) cout << "Yes\n";
	else cout << "No\n";
	for (int i = 0 ; i < n*m; i++)
	{
		free(adj[i]);
	}
	free(adj);
	adj = NULL;
}
