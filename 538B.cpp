#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int binary(int i)
{
	char ans[10];
	int index = 0;
	while(i > 0)
	{
		ans[index] = i % 2 + '0';
		i/= 2;
		++index;
	}
	ans[index] = '\0';
	reverse(ans, ans + index);
	return atoi(ans);
}

void solve()
{
	for (int i = 0 ; i <= 127; i++)
	{
		v.push_back(binary(i));
	}
}

int bs(int chave)
{
	int l = 0;
	int u = v.size() - 1;
	int aux = u;
	
	int mid;
	
	while (l <= u)
	{
		mid = (l + u) / 2;
		
		if (chave % v[mid] == 0) return v[mid];
		else
		{
			if (chave > v[mid])
			{
				if (mid + 1 <= aux)
				{
					if (chave % v[mid + 1] == 0) return v[mid + 1];
					else if (mid - 1 >= 0 && chave % v[mid - 1] == 0) return v[mid - 1];
					else if (chave <= v[mid + 1]) return v[mid];
					else
					{
						l = mid + 1;
					}
				}
				else return v[mid];
			}
			else
			{
				if (mid - 1 >= 0)
				{
					if (chave % v[mid - 1] == 0) return v[mid - 1];
					else if (mid + 1 <= aux && chave % v[mid + 1] == 0) return v[mid + 1];
					else if (chave >= v[mid - 1]) return v[mid - 1];
					else
					{
						u = mid - 1;
					}
				}
				else return v[mid];
			}
		}
	}
	return -1;
}


int main()
{
	int n;
	int aux;
	vector<int> ans;
	solve();
	while(cin >> n)
	{
		while(n > 0)
		{
			aux = bs(n);
			n-= aux;
			ans.push_back(aux);
		}
		cout << ans.size() << '\n';
		for (int i = 0 ; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
		ans.clear();
	}
}
