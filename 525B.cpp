#include <bits/stdc++.h>

using namespace std;
int main ()
{
	vector<int> v;
	
	string s1;
	
	int q;
	int x;
	int pos;
	
	while(cin >> s1){
	int tam = s1.size();
	cin >> q;
	getchar();
	
	v.assign(tam, 0);
	
	for (int i = 0 ; i < q; i++)
	{
		cin >> x;
		v[x - 1]++;
	}
	tam = tam / 2 + tam % 2;
	int cont = 0;
	for (int i = 0 ; i < tam; i++)
	{
		cont+= v[i];
		if (cont % 2 == 0) continue;
		
		char aux = s1[i];
		s1[i] = s1[s1.size() - i - 1];
		s1[s1.size() - 1 - i] = aux;
	}
	cout << s1 << '\n';
	v.clear();
	}
}
