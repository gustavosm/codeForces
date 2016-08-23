#include <bits/stdc++.h>

#define P 'p'
#define W 'e'
#define B 'f'

using namespace std;
typedef struct node
{
	char cor;
	int pixels;
	struct node* d;
	struct node* de;
	struct node* ed;
	struct node* e;
}No;

No *insert(No* h, string s, int nivel)
{
	if (s.size() == 0) return NULL;
	char cor = s[0];
	if (h == NULL)
	{	
		char cor = s[0];
		if (cor == P)
		{
			h = (No*) malloc(sizeof(No));
			h->cor = P;
			h->pixels = 0;
			h->d = NULL;
			h->de = NULL;
			h->ed = NULL;
			h->e = NULL;
			h->d = insert(h->d, s.substring(1), nivel + 1);
		}
		else if (cor == W)
		{
			h = (No *) malloc(sizeof(No));
			h->cor = W;
			h->pixels = 0;
			h->d = NULL;
			h->de = NULL;
			h->ed = NULL;
			h->e = NULL;
		}
		else if (cor == B)
		{	
			h = (No *) malloc(sizeof(No));
			h->cor = B;
			h->pixels = (int)(1024 / (pow(4, nivel)));
			h->d = NULL;
			h->de = NULL;
			h->ed = NULL;
			h->e = NULL;		
		}
	}
	else
	{		
		if (cor == P)
		{
			h->
		}
	}
}
