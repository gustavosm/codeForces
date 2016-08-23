#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char *expressionToParse;

char peek()
{
    return *expressionToParse;
}

char get()
{
    return *expressionToParse++;
}

ll number()
{
    ll result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10*result + get() - '0';
    }
    return result;
}

ll factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        ll result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}

ll term()
{
    ll result = factor();
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= factor();
        else
            result /= factor();
    return result;
}

ll expression()
{
    ll result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}

int main()
{
	string s;
	string aux;
	int pos;
	
	while (getline(cin, s))
	{
		ll ans = s[0] - '0';
		pos = -1;
		aux.push_back(s[0]);
		for (int i = 1 ; i < s.size(); i += 2)
		{
			if (s[i] == '+') 
			{
				pos = i;
				break;
			}			
			aux.push_back(s[i]);
			aux.push_back(s[i + 1]);
			
			ans *= s[i + 1] - '0';
		}
		
		if (i >= s.size()) cout << ans << '\n';
		else
		{
			aux.push_back('(');	
			for (int i = pos; i < s.size(); i += 2)
			{
				
			}
		}
	}	

    return 0;
}
