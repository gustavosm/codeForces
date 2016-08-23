#include <bits/stdc++.h>


using namespace std;

typedef double lf;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;

#define INF 0x1b

struct point
{
	ll x, y;
	ull raio;
	
	point(){x = y = 0LL; raio = 0LL;}
	
	point(ll _x, ll _y, ull _r) : x(_x), y(_y), raio(_r){}
	
	bool ok(const point &other)
	{
		ll xx = abs(x - other.x);
		ll yy = abs(y - other.y);
		
		xx *= xx;
		yy *= yy;
		
		return (raio >= ((xx + yy) / raio));
	}
	
	ll manhattan(const point &other)
	{
		return (abs(x - other.x) + abs(y - other.y));
	}
};

vector<vector<ii > > g;

vector<point> p;

ll dist[105];
int n;

void dijkstra(int s)
{
	memset(dist, INF, sizeof dist);
	dist[s] = 0;
	priority_queue< ii, vector<ii>, greater<ii> > pq; 
	pq.push(ii(0, s));
	while (!pq.empty()) 
	{
		ii front = pq.top(); pq.pop();
		
		ll d = front.first;
		int u = front.second;
		
		if (d > dist[u]) continue;
		
		for (int j = 0; j < (int)g[u].size(); ++j) 
		{
			ii v = g[u][j];
			if (dist[u] + v.first < dist[v.second]) 
			{
				dist[v.second] = dist[u] + v.first;
				pq.push(ii(dist[v.second], v.second));
			} 
		} 
	}
}
int main()
{
	int cases;
	ll x1, y1, x2, y2;
	//ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n;
		g.assign(n + 2, vector<pair<ll, int> > ());
		p.clear();
		for (int i = 0 ; i < n ; ++i)
		{
			ll u, v;
			ull w;
			cin >> u >> v >> w;
			p.push_back(point(u, v, w));
		}
		
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0; j < n ; ++j)
			{
				if (i != j)
				{
					if (p[i].ok(p[j]))
						g[i].push_back(make_pair(min(2LL, p[i].manhattan(p[j])), j));
					else g[i].push_back(make_pair(p[i].manhattan(p[j]), j));
				}
			}
		}
		cin >> x1 >> y1;
		point s = point(x1, y1, 0);
		for (int i = 0 ; i < n ; ++i)
		{
			ll distd = s.manhattan(p[i]);
			g[n].push_back(make_pair(distd, i));
		}
		cin >> x2 >> y2;
		point e = point(x2, y2, 0);
		for (int i = 0 ; i < n ; ++i)
		{
			ll distd = e.manhattan(p[i]);
			g[i].push_back(make_pair(distd, n + 1));
		}
		
		ll distd = e.manhattan(s);
		
		g[n].push_back(make_pair(distd, n + 1));
		
		dijkstra(n);
		
		cout << dist[n + 1] << '\n';
	}
}
