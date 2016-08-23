#include <bits/stdc++.h>

using namespace std;


bitset<105> primes;
vector<int> v;
void crivo()
{
	primes.set();
	for (int i = 2; i <= 50; ++i)
	{
		if (primes[i])
		{
			v.push_back(i);
			for (int j = i + i; j <= 100; j += i)
				primes.reset(j);
		}
	}
}

int main()
{
	string response;
	crivo();
	
	int primo_escolhido = 0;
	int yes = 0;
	int flag = 1;
	for (int i = 0; i < (int)v.size(); ++i)
	{
		cout << v[i] << endl;
		cin >> response;
		
		if (response == "yes")
		{
			++yes;
			if (yes >= 2)
			{
				cout << "composite" << endl;
				flag = 0;
				break;
			}
			primo_escolhido = v[i];
		}
	}
	if (flag)
	{
		if (!primo_escolhido) cout << "prime" << endl;
		else if (primo_escolhido * primo_escolhido <= 100)
		{
			cout << primo_escolhido * primo_escolhido << endl;
			cin >> response;
			if (response == "yes")
				cout << "composite" << endl;
			else cout << "prime" << endl;
		}
		else cout << "prime" << endl;
	}
}
