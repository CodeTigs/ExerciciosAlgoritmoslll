#include <iostream>

using namespace std;
struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode *treenodeptr;

void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) // insere na raiz
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info) // insere na subarvore esquerda
        tInsere(p->esq, x);
    else // insere na subarvore direita
        tInsere(p->dir, x);
}
int tPesq(treenodeptr arvore, int X, int &nChamadas)
{
    if (arvore == NULL) // elemento ñ encontrado
        return NULL;
    else if (X == arvore->info) // elemento encontrado na raiz
        return nChamadas;
    else if (X < arvore->info){ // procura na sub´arvore esquerda
    	nChamadas++;
        tPesq(arvore->esq, X,nChamadas);
	}
    else{ // procura na sub´arvore direita
    	nChamadas++;
        tPesq(arvore->dir, X,nChamadas);
	}
}
int main()
{
    treenodeptr arvore = NULL; // ponteiro para a raiz
    int x;
    int N;
    int nChamadas = 0;

    cin >> N;
    while(N != -1) {
        tInsere(arvore, N);
        cin >> N;
    }
    cin >> x;

	
    cout << x <<" encontrado na profundidade "<< tPesq(arvore, x,nChamadas)<<endl;
    //20 encontrado na profundidade 0
    

    return 0;
}

