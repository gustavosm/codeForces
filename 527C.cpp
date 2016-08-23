#include <bits/stdc++.h>


using namespace std;


set<int> a1,a2;
multiset<int> b1, b2;


set<int> ::iterator it1, it2;


int main()
{
	int w, h, n;
	char c;
	int x;
	
	while (cin >> w >> h >> n)
	{
		a1.insert(0); a1.insert(w);
		a2.insert(0); a2.insert(h);
		b1.insert(w); b2.insert(h);
		
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> c >> x;
			
			
			if (c == 'H')
			{
				it1 = a2.lower_bound(x);
				it2 = --it1; ++it1;
				int num = *it1 - *it2;
				b2.erase(b2.find(num));
				
				a2.insert(x);
				b2.insert(x - *it2);
				b2.insert(*it1 - x);
			}
			else
			{
				it1 = a1.lower_bound(x);
				it2 = --it1; ++it1;
				int num = *it1 - *it2;
				b1.erase(b1.find(num));
				
				a1.insert(x);
				b1.insert(x - *it2);
				b1.insert(*it1 - x);
			}
			
			cout << (long long)(*b1.rbegin()) * (long long )(*b2.rbegin()) << '\n';
		}
		
		a1.clear();
		b1.clear();
		a2.clear();
		b2.clear();
	}
}
