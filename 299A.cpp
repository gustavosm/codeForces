#include <bits/stdc++.h>

using namespace std;
int main()
{
	char ans[30][30] = {"ninety", "eighty", "seventy", "sixty", "fifty", "forty", "thirty", "twenty", "ten"};
	char ans2[30][30] = {"nine","eight", "seven", "six", "five", "four", "three", "two", "one", "zero"};
	
	int n;
	
	while(cin >> n)
	{
	
		if (n % 10 == 0 && n != 0)
			cout << ans[9 - n / 10] << '\n';
		else if (n % 10 == 0 && n == 0) cout << "zero\n";
		else
		{
			if (n > 10 && n < 20)
			{
				switch(n)
				{
					case 11:
						cout << "eleven\n";
						break;
					case 12:
						cout << "twelve\n";
						break;
					case 13:
						cout << "thirteen\n";
						break;
					case 14:
						cout << "fourteen\n";
						break;
					case 15:
						cout << "fifteen\n";
						break;
					case 16:
						cout << "sixteen\n";
						break;
					case 17:
						cout << "seventeen\n";
						break;
					case 18:
						cout << "eighteen\n";
						break;
					case 19:
						cout << "nineteen\n";
						break;
				}
			}
			else
			{
				if (n < 10)
				{
					cout << ans2[10 - n - 1]  << '\n';
				}
				else cout << ans[10 - n / 10 - 1] << "-" << ans2[10 - n % 10 - 1] << '\n';
			}
		
		}
	}
}
