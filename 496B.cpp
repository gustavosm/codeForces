#include <bits/stdc++.h>


using namespace std;

string s;
vector<string> v;
int n;

int main()
{
	while (cin >> n)
	{
		char c;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> c;
			s.push_back(c);			
		}
		for (int i = 0 ; i < n ; ++i)
		{
			string aux;
			aux.push_back('0');
			for (int j = (i + 1) % n; j != i; j = (j + 1) % n)
				aux.push_back((s[j] + 10 - s[i]) % 10 + '0');
				
			v.push_back(aux);
		}


		cout << *min_element(v.begin(), v.end()) << '\n';
		v.clear();
		s.clear();
	}
}
