#include <bits/stdc++.h>


using namespace std;


string ans;
string in;
int n;

int main()
{
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> in;
		
		if (in[0] == '0')
		{
			cout << "0\n";
			return 0;
		}
		int maior1 = 0;
		int uns = 0;
	
		for (int i = 0 ; i < in.size(); ++i)
		{
			if (in[i] == '1') ++uns;
			else if (in[i] != '0') ++maior1;
		}
		
		if ((uns <= 1) && (maior1 == 0))
		{
			if (ans == "")
			{
				ans = in;
			}
			else if (in.size() > 1) 
				ans += in.substr(1);
		}
		else
			if (ans == "")
				ans = in;
			else
				ans = in + ans.substr(1);
	}	
	cout << ans << '\n';
}
