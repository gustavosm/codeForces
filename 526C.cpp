#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int maior;
	
	int C, Hr, Hb, Wr, Wb;
	int qtdex;
	int qtdey;
	
	while(cin >> C >> Hr >> Hb >> Wr >> Wb)
	{
		maior = -1;
		qtdex = 0;
		qtdey = 1;
		
		while (Wb * qtdey <= C)
		{
			qtdex = (C - Wb * qtdey)/Wr;
			if (maior < Hr * qtdex + Hb * qtdey)
				maior = Hr * qtdex + Hb * qtdey;
			qtdey++;
		}
		cout << maior << '\n';
	}
}
