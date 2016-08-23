#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<int, int> m1, m2, m3;
	
	int x1, x2;	
	int n;
	int x;
	
	
	cin >> n;
	
	for (int i = 0 ; i < n ; i++)
	{
		cin >> x;
		
		m1[x]++;
	}
	for (int i = 0 ; i < n - 1; i++)
	{
		cin >> x;
		
		m2[x]++;
	}
	for (int i = 0 ; i < n - 2; i++)
	{
		cin >> x;
		
		m3[x]++;
	}
	
	for (map<int, int> :: iterator it = m1.begin() ; it != m1.end(); it++)
	{		
		if (it->second > m2[it->first]) {x1 = it->first;break;}
	}
	for (map<int, int> :: iterator it = m2.begin() ; it != m2.end(); it++)
	{		
		if (it->second > m3[it->first]) {x2 = it->first;break;}
	}	
	
	cout << x1 << '\n' << x2 << '\n';
}
