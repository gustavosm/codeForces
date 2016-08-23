#include <bits/stdc++.h>


using namespace std;


string s, s_aux;
vector<string> v;

int bs()
{
	int b = 0;
	int e = v.size() - 1;
	int mid;
	
	while (b <= e)
	{
		mid = (b + e) >> 1;
		
		if (v[mid] == s) return mid + 1;
		if (v[mid] < s)
			b = mid + 1;
		else e = mid - 1;
	}
	return -1;
}


int main()
{
	int cases;
	cin >> cases;
	
	int freq[10] = {0};
	while (cases--)
	{
		cin >> s_aux;
		
		s = s_aux;
		int n = s.size();
		
		memset(freq, 0, sizeof freq);
		
		for (int i = 0 ; i < n; ++i)
			++freq[s[i] - '0'];
			
		sort(s_aux.begin(), s_aux.end());
		
		do
		{
			v.push_back(s_aux);
		}while(next_permutation(s_aux.begin(), s_aux.end()));
		sort(v.begin(), v.end());
		
		int idx = bs();
		int t = v.size();
		
		cout << setprecision(10) << fixed << double(t - idx) / double(t) << '\n';
	}
}
