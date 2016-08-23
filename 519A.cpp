#include <bits/stdc++.h>


using namespace std;

int main()
{
	string s;
	
	int b = 0;
	int w = 0;
	while(cin >> s)
	{
		for (int i =  0 ; i < s.size(); i++)
		{
			if (s[i] == 'q') b += 9;
			
			if (s[i] == 'r') b += 5;
			
			if (s[i] == 'b') b += 3;
			
			if (s[i] == 'n') b += 3;
			
			if (s[i] == 'p') b += 1;
			
			
			if (s[i] == 'Q') w += 9;
		
			if (s[i] == 'R') w += 5;
			
			if (s[i] == 'B') w += 3;
			
			if (s[i] == 'N') w += 3;
			
			if (s[i] == 'P') w += 1;
			
		}
	}
	
	if (b > w) cout << "Black\n";
	else if (b == w) cout << "Draw\n";
	else cout << "White\n";
}
