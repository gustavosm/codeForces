#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main ()
{
	int x;
	int q;
	ll area;
	ll p1;
	ll p2;
	
	vector<ll> v;
	
	while(cin >> q){
	v.assign(q, 0);
	
	for (int i = 0; i < q; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	area = 0;
	ll cont = 0;
	
	for (int i = q - 1; i > 0; i--)
	{
		if (v[i] - v[i - 1] < 2)
		{
			if (cont == 0)
			{
				p1 = v[i - 1];
				cont++;
				i--;
			}
			else if(cont == 1)
			{
				area+= p1 * v[i - 1];
				cont = 0;
				i--;
			}
		}
	}
	
	cout << area << '\n';
	v.clear();
	}
}
