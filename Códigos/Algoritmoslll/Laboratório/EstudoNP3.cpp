#include <iostream>
#include <list>
using namespace std;
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;
void tInsere(treenodeptr &p, int x)//coloca o x na arvore
{
	if (p == NULL)
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info)   // coloca x na subarvore esquerda
		tInsere(p->esq, x);
	else
		tInsere(p->dir, x);//coloca x na subarvore a direita
}
void mostraPares(treenodeptr t)
{
	treenodeptr n;
	list<treenodeptr> q;
	if (t != NULL)
	{
		q.push_back(t);
		while (!q.empty())
		{
			n = *q.begin();
			q.pop_front();
			if (n->esq != NULL)
				q.push_back(n->esq);
			if (n->dir != NULL)
				q.push_back(n->dir);
			if(n->info % 2 == 0)
				cout << n->info << endl;
		}
	}
}


void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
	treenodeptr arvore = NULL;
	int N;
	cin >> N;
	while(N != -1)
	{
		tInsere(arvore, N);
		cin >> N;
	}
	mostraPares(arvore);

	tDestruir(arvore);

	return 0;
}
