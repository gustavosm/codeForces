#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

const int N = 4004;

int n;
ll v[N],d[N],p[N];
vi ans;

int main()
{
	//ios::sync_with_stdio(0);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) cin >> v[i] >> d[i] >> p[i];
	for(int i=1;i<=n;++i)
	{
		if( p[i] >= 0 )
		{
			int j = i+1;
			ans.pb(i);
			ll aux = 0;
			while( j <= n )
			{
				if (p[j] >= 0)
				{
					p[j]-=(v[i] + aux);
					if (v[i]) --v[i];
					if (p[j] < 0) aux += d[j];
				}
				j++;
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<(int)ans.size();++i)
	{
		cout << ans[i] << ' ';
	}
	printf("\n");


	return 0;
}
/*#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

vector<pair<ll, pair<ll, ll> > > q;


int main()
{
	int n;
	ll vi, di, pi;
	
	vector<int> ans;
	
	cin >> n;
	
	for (int i = 0 ; i < n  ; ++i)
	{
		cin >> vi >> di >> pi;
		
		q.push_back(make_pair(vi, make_pair(di, pi)));
	}
	
	int i = 0 ;
	while (i < n)
	{
		pair<ll, pair<ll, ll> > u = q[i];
		if (u.second.second >= 0)
			ans.push_back(i + 1);
		else
		{
			//for (int aux = i + 1; aux < n ; ++aux)
				//q[aux].second.second -= u.second.first;
			++i;
			continue;
		}
		ll s = u.first;
		
		for (int aux = i + 1; aux < n; ++aux)
		{
			if (q[aux].second.second >= 0)
			{
				q[aux].second.second -= s;
				if (q[aux].second.second < 0) s += q[aux].second.first;	
			
				if (u.first)--s, --u.first;
			}
		}
		++i;		
	}
	
	cout << ans.size() << '\n';
	for (int i = 0 ; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}*/
