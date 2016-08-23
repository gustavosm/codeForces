#include <bits/stdc++.h>


using namespace std;

typedef long long ll;


ll tab[26][26];
vector <string> v;

string quantas_letras(string &s)
{
	int freq[26];
	
	string ret;
	memset(freq, 0, sizeof freq);
	for (int i = 0 ; i < s.size(); ++i)
	{
		++freq[s[i] - 'a'];
		if (freq[s[i] - 'a'] == 1) ret.push_back(s[i]);
	}
	
	return ret;
}

int main()
{	
	string s;
	int n;
	
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> s;
		v.push_back(s);
	}
	ll ans = 0;
	memset(tab, 0, sizeof tab);
	
	for (int i = 0 ; i < n ; ++i)
	{
		string ret = quantas_letras(v[i]);
		
		if (ret.size() <= 2)
		{
			sort(ret.begin(), ret.end());
		//	cout << "para " << v[i] << " deu " << ret << '\n';	
			if (ret.size() == 1)
			{
				for (int k = 0 ; k < 26; ++k)
				{
					int aaa = min(ret[0] - 'a', k);
					int bbb = max(ret[0] - 'a', k);
					
					tab[aaa][bbb] += (ll)v[i].size();
				}
			}
			else
				tab[ret[0] - 'a'][ret[1] - 'a'] += (ll)v[i].size();
		}
	}
	
	for (int i = 0 ; i < 26 ; ++i)
	{
		for (int j = i; j < 26 ; ++j)
			ans = max(ans, tab[i][j]);
	}
	
	cout << ans << '\n';
}
