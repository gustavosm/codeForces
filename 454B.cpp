#include <bits/stdc++.h>


using namespace std;

list<int> v1;
list<int> v2;
int n;

int equal()
{
	for (list<int> :: iterator i = v1.begin(), j = v2.begin() ; i != v1.end(); ++i, ++j)
		if (*i != *j) return 0;
	return 1;
}

int ordered()
{
	list<int> :: iterator i = v2.begin();
	++i;
	for (list<int> :: iterator j = v2.begin() ; i != v2.end(); ++i, ++j)
		if (*j > *i) return 0;
		
	return 1;
}
int main()
{
	
	int x;
	list<int>::reverse_iterator it;
	
	while (cin >> n)
	{
		for (int i = 0 ; i < n ; i++)
		{
			cin >> x;
			v1.push_back(x);
			v2.push_back(x);
		}
		
		int flag = 0;
		int passos = 0;
		while (1)
		{
			if (ordered())
			{
				flag = 2;
				break;
			}
			++passos;
			it = v2.rbegin();
			v2.push_front(*it);
			v2.pop_back();
			
			if (equal())
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) cout << "-1\n";
		else cout << passos << '\n';
		v1.clear();
		v2.clear();
	}
}
