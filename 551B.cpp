#include <bits/stdc++.h>


using namespace std;


int fa[30], fb[30], fc[30];


int main()
{
	string a, b, c;
	
	int subb;
	int subc;
	
	cin >> a >> b >> c;
	
	subb = subc = 0;
	
	memset(fa, 0, sizeof fa);
	memset(fb, 0, sizeof fb);
	memset(fc, 0, sizeof fc);
	
	for (int i = 0 ; i < a.size(); ++i) ++fa[a[i] - 'a'];
	for (int j = 0 ; j < b.size(); ++j)	++fb[b[j] - 'a'];
	for (int j = 0 ; j < c.size(); ++j)	++fc[c[j] - 'a'];
		
	int mn = INT_MAX;
	int mx = -1;
	
	int flag = 0;
	
	for (int freq = 0; ; ++freq)
	{
		for (int i = 0 ; i < 26; ++i)
		{
			if (fb[i] * freq > fa[i])
			{
				flag = 1;
				break;
			}
		}
		
		if (flag) break;
		
		for (int i = 0 ; i < 26; ++i)
		{
			if (fc[i])
				mn = min(mn, (fa[i] - fb[i] * freq) / fc[i]); //pegar a frequencia que c pode estar na resposta
		}
		
		if (mn + freq > mx)
		{
			mx = mn + freq;
			subb = freq;
			subc = mn;
		}		
	}	
	for (int i = 0 ; i < subb; ++i) cout << b;
	for (int i = 0 ; i < subc; ++i) cout << c;
	for (int i = 0 ; i < 26; ++i)
		for (int j = 0 ; j < fa[i] - fb[i] * subb - fc[i] * subc ; ++j)
			cout << (char)(i + 'a');
	cout << '\n';
	
		
	
	
	
}
