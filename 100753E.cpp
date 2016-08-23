#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

typedef pair<ll, ll> pi;

const ll INF = (ll)(1e17);
vector<vector<pi> > g;

vector<ll> d1;
vector<ll> d2;
int n;

int grau[10005];
ll a[1000005];
ll b[1000005];
ll wg[1000005];

void dijkstra(int s, vector<ll>&dist)
{
	dist.assign(n, INF);
	dist[s] = 0;
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq; 
	pq.push(make_pair(0, s));
	
	while (!pq.empty())
	{		
		pair<ll, ll> u = pq.top(); pq.pop();
		
		ll v = u.second;
		
		ll w = u.first;
		
		if (dist[v] < w) continue;
		dist[v] = w;
		
		for (int i = 0 ; i < (int)g[v].size(); ++i)
		{
			ll v2 = g[v][i].second;
			ll w2 = g[v][i].first;
			
			if (dist[v2] > dist[v] + w2)
			{
				dist[v2] = dist[v] + w2;
				pq.push(make_pair(dist[v2], v2));
			}
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int m, k;
	int u, v, w;
	
	cin >> n >> m >> k;
	memset(grau, 0, sizeof grau);
	
	for (int i = 0 ; i < k; ++i)
		cin >> u;
	
	g.assign(n + 5, vector<pi>());
	
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> u >> v >> w;
		--u, --v;
		a[i] = u;
		b[i] = v;
		wg[i] = w;
		//cout << "colocando " << u << ' ' << v << '\n';
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}
	
	dijkstra(0, d1);
	
	if (d1[n - 1] == INF)
	{
		cout << "no\n";
		return 0;
	}
	dijkstra(n - 1, d2);
	
	
	for (int i = 0 ; i < m; ++i)
	{
		//cout << "DE " << i << " a " << g[i][j].second << " tenho " << dist[i] + g[i][j].first + d2[g[i][j].second] << '\n';
		if (d1[a[i]] + wg[i] + d2[b[i]] == d1[n - 1] || d1[b[i]] + wg[i] + d2[a[i]] == d1[n - 1])
		{
			++grau[a[i]];
			++grau[b[i]];
		}
	}
	
	if (grau[0] > 1 || grau[n - 1] > 1) 
	{
		cout << "yes\n";
		return 0;
	}
	for (int i = 1; i < n - 1; ++i)
	{
		if (grau[i] > 2)
		{
			cout << "yes\n";
			return 0;
		}
	}
	cout << "no\n";
}
