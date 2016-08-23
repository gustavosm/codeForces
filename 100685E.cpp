#include <bits/stdc++.h>


using namespace std;

typedef long double ld;

vector<pair<ld, int> > neg, pos;
vector<int> ans;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int n;
	ld d;
	
	cin >> n;
	int zero = 0, idx;
	
	
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> d;
		if (d > 0.0)
			pos.push_back(make_pair(d, i));
		else if (d < 0.0)
			neg.push_back(make_pair(d, i));
		else ++zero, idx = i + 1;
	}
	
	int psz = pos.size();
	int nsz = neg.size();
	if (zero == n) cout << "1\n1\n";
	else if (n == 2)
	{
		if (zero == 1 && nsz == 1) cout << "1\n" << idx << '\n';
		else if (zero == 1 && psz == 1) cout << "1\n" << pos[0].second + 1 << '\n';
		else if (psz == 1) cout << "1\n" << pos[0].second + 1 << '\n';
		else if (nsz == 2) cout << "2\n1 2\n";
		else if (psz == 2)
		{
			sort(pos.begin(), pos.end());
			ld d = pos[0].first;
			ld d2 = pos[1].first;
			if (d * d2 > d2) cout << "2\n1 2\n";
			else cout << "1\n" << pos[1].second + 1<< '\n';
		}
	}
	else
	{
		sort(neg.rbegin(), neg.rend());
		sort(pos.begin(), pos.end());
		
		if (psz == 0)
		{
			ld mx1 = neg[nsz - 1].first;
			int i;
			for (i = nsz - 2; i >= 0; --i)
			{
				if (neg[i].first >= -1.0) break;
				mx1 *= neg[i].first;
			}
		
			if (mx1 < 0.0 && i >= 0)
			{
				if (mx1 * neg[i].first > mx1 / (i + 1 == nsz - 1 ? 1.0 : neg[i + 1].first))
					mx1 *= neg[i].first, --i;
				else
					mx1 /= neg[i + 1].first, ++i;
			}
			
			for (int j = nsz - 1; j > i; --j)
				ans.push_back(neg[j].second + 1);
		}
		else if (nsz == 0)
		{
			ld mx1 = pos[psz - 1].first;
			int i;
			for (i = psz - 2; i >= 0; --i)
			{
				if (pos[i].first <= 1.0) break;
				mx1 *= pos[i].first;
			}
		
			for (int j = psz - 1; j > i; --j)
				ans.push_back(pos[j].second + 1);
		}
		else
		{
			ld mx1 = pos[psz - 1].first;
			int i;
			for (i = psz - 2; i >= 0; --i)
			{
				if (pos[i].first <= 1.0) break;
				mx1 *= pos[i].first;
			}
		
			for (int j = psz - 1; j > i; --j)
				ans.push_back(pos[j].second + 1);
		
			ld mx2 = neg[nsz - 1].first;
			int k;
			for (k = nsz - 2; k >= 0; --k)
			{
				if (neg[k].first >= -1.0) break;
				mx2 *= neg[k].first;
			}
		
			if (mx2 < 0.0 && k >= 0)
			{ 
				if (mx2 * neg[k].first > mx2 / (k + 1 == nsz - 1 ? 1.0 : neg[k + 1].first))
					mx2 *= neg[k].first, --k;
				else
					mx2 /= neg[k + 1].first, ++k;
			}
		
			if (mx1 > 1.0 && mx2 > 1.0)
			{
				for (int j = nsz - 1; j > k; --j)
					ans.push_back(neg[j].second + 1);
			}
			else if (mx2 > 1.0 || mx2 > mx1)
			{
				ans.clear();
				for (int j = nsz - 1; j > k; --j)
					ans.push_back(neg[j].second + 1);
			}
		}
	
		cout << ans.size() << '\n';
		sort(ans.begin(), ans.end());
	
		for (int i = 0 ; i < ans.size(); ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}
} 
