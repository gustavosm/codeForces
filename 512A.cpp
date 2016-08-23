#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > v(26,vector<int> ());
vector<int> visited(26,0);
bool havecicle = false;
stack<int> pilha;

void cicle(int n)
{
	visited[n] = 1;
	for(int i = 0 ; i < v[n].size(); i++)
	{
		if (visited[v[n][i]] == 1)
		{
			havecicle = true;
			break;
		}
		else if (!visited[v[n][i]])
			cicle(v[n][i]);
	}
	visited[n] = 2;
}
void dfs(int c)
{
	visited[c] = 1;
	for (int i = 0 ; i < v[c].size(); i++)
	{
		if (!visited[v[c][i]])
			dfs(v[c][i]);
	}
	pilha.push(c);
}
int main ()
{
	vector<string> list;
	
	int n;
	int arestas;
	int pos;
	
	string s;
	
	cin >> n;
	getchar();
	while(n--)
	{
		getline(cin, s);
		list.push_back(s);
	}
	for (int i = 0 ; i < list.size() - 1; i++)
	{
		pos = 0;
		while(pos < list[i].size() && pos < list[i+1].size() && list[i][pos] == list[i+1][pos]) pos++;
		if (pos < list[i].size() && pos < list[i+1].size())
		{
			v[list[i][pos] - 'a'].push_back(list[i+1][pos]-'a');
		}
		else
		{
			if (list[i].size() > list[i+1].size())
				havecicle = true;
		}
	}
	for (int i = 0 ; i < 26; i++)
		if (!visited[i]) cicle(i);
	if (havecicle) cout << "Impossible\n";
	else
	{
		visited.clear();
		visited.assign(26,0);
		for (int i = 0 ; i < 26; i++)
		{
			if (!visited[i])
				dfs(i);
		}
		while(!pilha.empty())
		{
			cout << (char)(pilha.top()+'a');
			pilha.pop();
		}
		cout << '\n';
	}
	
}
