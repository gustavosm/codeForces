#include <bits/stdc++.h>


using namespace std;


map<pair<char, int>, int> m1, m2;



int main()
{
	int n, s;
	
	char c; int price, qtde;
	
	
	while (cin >> n >> s)
	{
		while (n--)
		{
			cin >> c >> price >> qtde;
			
			
			pair<char, int> p(c, price);
			if (c == 'S')
			{
				m1[p] += qtde;
			}
			else
			{
				m2[p] += qtde;
			}
		}
		map<pair<char, int>, int> ::reverse_iterator it2;
		map<pair<char, int> , int> :: iterator it;
		it = m1.begin();
		vector<pair< pair<char, int>, int> > v;
		for (int i = 0; i < s && it != m1.end() ; ++i, ++it)
		{
			v.push_back(make_pair(it->first, it->second));
		}
		for (int i = v.size() - 1;  i >= 0 ; --i) cout << v[i].first.first << ' ' << v[i].first.second << ' ' << v[i].second << '\n';
		v.clear();
		it2 = m2.rbegin();
		for (int i = 0; i < s && it2 != m2.rend(); ++i)
		{
			pair<char, int> p = (it2->first);
			cout << p.first << ' ' << p.second << ' ' << it2->second << '\n';
			++it2;
		}
		
		m1.clear();
		m2.clear();
	}
}
