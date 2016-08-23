#include <bits/stdc++.h>


using namespace std;


char value(int i)
{
	if (i == 0) return 'A';
	if (i == 2) return 'B';
	if (i == 4) return 'C';
}
int main()
{
	int ret[6];
	
	
	while (cin >> ret[0] >> ret[1] >> ret[2] >> ret[3] >> ret[4] >> ret[5])
	{
		int area = (ret[0] * ret[1]) + (ret[2] * ret[3]) + (ret[4] * ret[5]);
		string s;
		double sqrtarea = sqrt(area);
		
		if (sqrtarea == (int)sqrtarea)
		{
			int lado = (int)sqrtarea;
			int flag = 0;
			int pos;
			for (int i = 0 ; i < 6; i += 2)
			{
				if (ret[i] == lado || ret[ i + 1 ] == lado)
				{
					++flag;
					pos = i;
					for (int k = 0 ; k < (ret[i] == lado? ret[ i + 1] : ret[i]); ++k)
					{
						for (int j = 0 ; j < (ret[i] == lado? ret[i] : ret[i + 1]); ++j)
							s.push_back(value(i));
						s.push_back('\n');
					}
				}
			}
			if (flag == 3) cout << lado << '\n' << s << '\n';
			else if (flag == 1)
			{
				char c, d;
				c = 'B';
				d = 'C';
				if (pos == 2)
				{
					ret[2] = ret[0];
					ret[3] = ret[1];
					c = 'A';
				}
				else if (pos == 4)
				{
					ret[4] = ret[0];
					ret[5] = ret[1];
					d = 'A';
				}
				if (ret[2] + ret[4] == lado)
				{
					for (int k = 0 ; k < ret[3]; ++k)
					{
						for (int j = 0 ; j < ret[2]; ++j)
							s.push_back(c);
						for (int j = 0 ; j < ret[4] ; ++j)
							s.push_back(d);
						s.push_back('\n');
					}
					cout << lado << '\n' << s << '\n';
				}
				
				else if (ret[2] + ret[5] == lado)
				{
					for (int k = 0 ; k < ret[3]; ++k)
					{
						for (int j = 0 ; j < ret[2]; ++j)
							s.push_back(c);
						for (int j = 0 ; j < ret[5] ; ++j)
							s.push_back(d);
						s.push_back('\n');
					}
					cout << lado << '\n' << s << '\n';
				}
				else if (ret[3] + ret[4] == lado)
				{
					for (int k = 0 ; k < ret[2]; ++k)
					{
						for (int j = 0 ; j < ret[3]; ++j)
							s.push_back(c);
						for (int j = 0 ; j < ret[4] ; ++j)
							s.push_back(d);
						s.push_back('\n');
					}
					cout << lado << '\n' << s << '\n';
				}
				
				else if (ret[3] + ret[5] == lado)
				{
					for (int k = 0 ; k < ret[2]; ++k)
					{
						for (int j = 0 ; j < ret[3]; ++j)
							s.push_back(c);
						for (int j = 0 ; j < ret[5] ; ++j)
							s.push_back(d);
						s.push_back('\n');
					}
					cout << lado << '\n' << s << '\n';
				}
				else cout << "-1\n";
			}
			else cout << "-1\n";
		}
		else cout << "-1\n";
		
	}
}
