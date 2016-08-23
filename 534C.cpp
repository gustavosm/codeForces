#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n, A;
	int sum;
	int v[200006];
	
	while (cin >> n >> A)
	{
		sum = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> v[i];
			
			sum += v[i];
			
		}
		
		for (int i = 0 ; i < n ; ++i)
		{
			if (i) cout << ' ';
			if (sum - v[i] + 1 > A)
			{
				int aux = v[i] - 1;
				while (sum - aux > A)
					--aux;
				cout << aux;
				sum -= aux;
			}
			if (sum - v[i] + 1 == A)
			{
				cout << 1;
				--sum;
			}
			else
			{
				int aux = 1;
				
				while ((sum - v[i]) + aux < A)
				{
					++aux;
				}
				cout << aux;
				
				sum = sum - v[i] + aux;
			}
		}
		cout << '\n';
	}
}
