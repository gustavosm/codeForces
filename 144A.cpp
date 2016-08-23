#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int min;
	int max;
	int posmx;
	int posmn;
	
	int line[110];
	
	int n;
	
	cin >> n;
	
	for (int i = 0 ; i < n; i++)
	{
		cin >> line[i];
	}
	
	max = *max_element(line, line + n);
	min = *min_element(line, line + n);
	
	posmx = -1;
	posmn = -1;
	for (int i = 0 ; i < n ; i++)
	{
		if (line[i] == max && posmx == -1)
			posmx = i;
		if (line[i] == min && posmn < i)
			posmn = i;
	}
	if (posmn < posmx) posmx--;
	cout << posmx + (n - 1 - posmn) << '\n';
}
