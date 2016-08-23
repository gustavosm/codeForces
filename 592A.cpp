#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

string v[8];

int main()
{
	int i = 0;
	while (cin >> v[i++]); 
	int pontA;
	int pontB;
	pontA = pontB = 12498714;
	int flag = 0;
	for (int i = 0 ; i < 8 ; ++i)
	{
		for (int j = 0 ; j < 8 ; ++j)
		{
			/*
			On his move player A must choose exactly one white pawn and move it one step upward and player B (at his turn) must choose exactly one black pawn and move it one step down. Any move is possible only if the targeted cell is empty. It's guaranteed that for any scenario of the game there will always be at least one move available for any of the players.

Moving upward means that the pawn located in (r, c) will go to the cell (r - 1, c), while moving down means the pawn located in (r, c) will go to the cell (r + 1, c). Again, the corresponding cell must be empty, i.e. not occupied by any other pawn of any color.
			*/
			if (v[i][j] == 'W')
			{
				int aux = i - 1;
				while (aux >= 0 && v[aux][j] == '.')
					--aux;
				if (aux == -1)
				{
					pontA = i;
					flag = 1;
					break;
				}
			}
			
		}
		if (flag) break;
	}
	flag = 0;
	for (int i = 7 ; i >= 0; --i)
	{
		for (int j = 0 ; j < 8 ; ++j)
		{
			/*
			On his move player A must choose exactly one white pawn and move it one step upward and player B (at his turn) must choose exactly one black pawn and move it one step down. Any move is possible only if the targeted cell is empty. It's guaranteed that for any scenario of the game there will always be at least one move available for any of the players.

Moving upward means that the pawn located in (r, c) will go to the cell (r - 1, c), while moving down means the pawn located in (r, c) will go to the cell (r + 1, c). Again, the corresponding cell must be empty, i.e. not occupied by any other pawn of any color.
			*/
			if (v[i][j] == 'B')
			{
				int aux = i + 1;
				while (aux < 8 && v[aux][j] == '.')
					++aux;
				if (aux == 8)
				{
					pontB = 7 - i;
					flag = 1;
					break;
				}
			}
		}
		if (flag) break;
	}
	if (pontA <= pontB) cout << "A\n";
	else cout << "B\n";
}
