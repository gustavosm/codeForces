#include <bits/stdc++.h>


using namespace std;

int main()
{
	string s1;
	
	int aux;
	
	
	while(cin >> s1)
	{
		if (s1.size() <= 2)
		{
			int t =  (s1.size() > 1 ? (s1[0] - '0') * 10 +(s1[1] - '0') : s1[0] - '0');
			int t2 = s1[0] - '0';
			
			int t3 = 1;
			if (s1.size() > 1) t3 = s1[1] - '0';
			
			if (t % 8 == 0) cout << "YES\n" << t << '\n';
			else if (t2 % 8 == 0) cout << "YES\n" << t2 << '\n';
			else if (t3 % 8 == 0) cout << "YES\n" << t3 << '\n';
			else cout << "NO\n";
			
			continue;
		}
		int flag = 0;
		for (int i = 0 ; i < s1.size(); i++)
		{
			int t1 = s1[i] - '0';
			if (t1 % 8 == 0)  
			{
				cout << "YES\n" << t1 << '\n';
				flag = 1;
				break;
			}
			
			for (int j = i + 1; j < s1.size(); j++)
			{
				
				int t2 = t1 * 10 + s1[j] - '0';
				
				if (t2 % 8 == 0) 
				{
					cout << "YES\n" << t2 << '\n';
					flag = 1;
					break;
				}
				for (int k = j + 1; k < s1.size(); k++)
				{
					int t = t1 * 100 + ( s1[j] - '0') * 10 + (s1[k] - '0');
					
					if (t % 8 == 0)
					{
						cout << "YES\n" << t << '\n';
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
		
		if (!flag) cout << "NO\n";
	}
}
