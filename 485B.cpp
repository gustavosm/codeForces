#include <bits/stdc++.h>


using namespace std;


int main()
{
	long long mx, my, mxx, mxy;
	
	mx = my = 10000000000LL;
	mxx = mxy = -10000000000LL;
	
	long long x, y;
	
	int n;
	
	cin >> n;
	
	for (int i = 0 ;  i < n  ; ++i)
	{
		cin >> x >> y;
		
		mx = min(mx, x);
		my = min(my, y);
		
		mxx = max(mxx, x);
		mxy = max(mxy, y);
	}
	
	mxx -= mx;
	mxy -= my;
	mxx = max(mxx, mxy);
	cout << mxx * mxx << '\n';
}
