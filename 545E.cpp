#include <bits/stdc++.h>

#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define INF 99999999
using namespace std;
typedef pair<int, int> ii;
vector<int> d;

vector<vector<ii >  > v;
vector<int> path;
int n;

void dijkstra(int p)
{
	d.assign(n, INF);
	
	d[p] = 0;
	
	priority_queue<ii, vector<ii >, greater<ii > > q;
	q.push(ii(0, p));
	
	while(!q.empty())
	{
		int w = q.top().second;
		
		q.pop();
		
		for (int i = 0; i < v[w].size(); i++)
		{
			ii aux = v[w][i];
			
			if (d[w] + aux.second < d[aux.first])
			{
				d[aux.first] = d[w] + aux.second;
				path[aux.first] = w;
				q.push(ii(d[aux.first], aux.first));
			}
		}
	}
}
int main()
{
	int m;
	int i;
	int j;
	int u;
	int w;
	int p;
	int dest;
	int sum;
	
	while(cin >> n >> m)
	{
		v.assign(n, vector<ii > ());
		f(i, m)
		{
			cin >> u >> w >> p;
			--u;
			--w;
			v[u].pb(ii(w, p));
			v[w].pb(ii(u, p));			
		}
		path.assign(n, -1);
		sum = 0;
		cin >> dest;
		--dest;
		dijkstra(dest);
		
		f(i, n) sum+= d[i];
		
		cout << sum << '\n';
		
		f(i, n) if (path[i] != -1) cout << i << ' ';
		
		cout << '\n';
		v.clear();
		d.clear();
		path.clear();
	}
}
