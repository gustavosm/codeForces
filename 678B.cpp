#include <bits/stdc++.h>

using namespace std;

int leap(int year)
{
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}
int main()
{
	int start;
	int year;
	
	start = 0;
	int igual = -1;
	cin >> year;
	int i;
	int isleap = leap(year);
	for (i = 1000; ; ++i)
	{
		if (leap(i)) start += 2;
		else ++start;
		
		start = start % 7;
		if (start == igual && leap(i) == isleap) break;
		
		if (i == year) igual = start;
		
	}
	cout << i << '\n';
}
