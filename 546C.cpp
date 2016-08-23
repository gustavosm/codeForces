#include <bits/stdc++.h>

using namespace std;


vector<int> v1;
vector<int> v2;

int estadoinicial(queue<int> q1, queue<int> q2)
{
	int i = 0;
	int j = 0;
	while(i < v1.size() && !q1.empty() && q1.front() == v1[i])
	{
		q1.pop();
		i++;
	}
	j = i;
	i = 0;
	while(i < v2.size() && !q2.empty() && q2.front() == v2[i])
	{
		q2.pop();
		i++;
	}
	return q2.empty() && q1.empty() && j == v1.size() && i == v2.size();
}
int main()
{
	queue<int> q1, q2;
	
	int n;
	int c1;
	int c2;
	int x;
	
	
	
	while(cin >> n)
	{
		cin >> c1;
		
		for (int i = 0 ; i < c1; i++)
		{
			cin >> x;
			q1.push(x);
			v1.push_back(x);
		}
		cin >> c2;
		
		for (int i = 0 ; i < c2; i++)
		{
			cin >> x;
			q2.push(x);
			v2.push_back(x);
		}
		int rodada = 0;
		int flag = 0;
		while(!q1.empty() && !q2.empty())
		{
			int carta1 = q1.front();
			int carta2 = q2.front();
			q1.pop();
			q2.pop();
			
			if (carta1 > carta2)
			{
				q1.push(carta2);
				q1.push(carta1);
			}
			else
			{				
				q2.push(carta1);
				q2.push(carta2);
			}
			
			if (estadoinicial(q1, q2) || rodada > 500000)
			{
				flag = 1; break;
			}
			rodada++;
		}
		if (flag) cout << "-1\n";
		else
		{
			if (q1.empty()) cout << rodada << " 2\n";
			else cout << rodada << " 1\n";
		}	
		v1.clear();
		v2.clear();
		
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
			
	}
}
