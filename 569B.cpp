#include <bits/stdc++.h>


using namespace std;


map<int, vector<int> > m;


int main()
{
	int n;
	
	int x;
	vector<int> v;
	vector<int> aux[100005];
	
	cin >> n;
	
	for (int i = 0 ; i < n  ; ++i)
	{
		cin >> x;
		
		v.push_back(x);
		
		aux[x].push_back(i + 1);
	}
