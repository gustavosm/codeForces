#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

const ll N = 3LL * (ll)(1e5) + 5;

ll starts[N];
ll note[N];
ll v[N];

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	ll n, q;
	ll ans = 0;
	ll type, ntf;
	cin >> n >> q;
	
	memset(note, 0, sizeof note);
	memset(starts, 0, sizeof starts);
	
	ll b, e;
	b = e = 0;
	
	while (q--)
	{
		cin >> type >> ntf;
		
		if (type == 1)
		{
			--ntf;
			++note[ntf];
			++ans;
			v[e++] = ntf;
		}
		else if (type == 2)
		{
			--ntf;
			ans -= note[ntf];
			note[ntf] = 0;
			starts[ntf] = e;
		}
		else
		{
			for (int i = b; i < ntf; ++i)
			{
				ll notf = v[i];
				if (i >= starts[notf])
				{
					--note[notf];
					--ans;
					starts[notf] = i + 1;
				}
			}
			b = max(b, ntf);
		}
		
		cout << ans << '\n';
	}
}
