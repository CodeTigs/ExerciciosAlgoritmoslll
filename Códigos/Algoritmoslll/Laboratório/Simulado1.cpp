#include <iostream>
#include <cstring>
#include <string>

using namespace std;
 
void calcula_LPS(int lps[], string P, int tamP)
{
	// tamanho do maior prefixo que tambem eh sufixo anterior
    int tam = 0;
    
	lps[0] = 0; // caso base
	
    // o loop calcula lps[i] para i = 1 ate tamP-1 
    int i = 1; 
    while (i < tamP)
	{ 
        if (P[i] == P[tam]) // se encontrar uma letra que bate tanto como prefixo quanto como sufixo
		{
            tam++; // aumento o tamanho do maior prefixo que tambem eh sufixo
            lps[i] = tam; // salvo o valor para esse prefixo
            i++; // vou para o proximo prefixo
        } 
        else // (p[i] != p[tam]) se encontrar uma letra que nao bate como prefixo e sufixo
        {
            if (tam != 0) // se o tamanho do maior prefixo que tambem eh sufixo atual for diferente de 0
			{
                tam = lps[tam - 1]; // volto pro maior prefixo que tambem eh sufixo considerando o prefixo anterior
                // Note que neste caso nao incrementamos o 'i'
			}
            else // se o tamanho do maior prefixo que tambem eh sufixo atual for 0
            { 
                lps[i] = 0; // o maior prefixo que tambem é prefixo agora vale 0
                i++; // vou para o proximo prefixo
            } 
        } 
    }			
}

int kmp(string T, string P,int tamT, int tamP)
{
	int lps[tamP]; // vetor que indica para onde voltarei no padrao quando ocorrer um mismatch
				   // lps -> indica o tamanho do maior sufixo de p[0...i] que tambem eh prefixo de p[0...i] (exceto a string inteira)
	
	calcula_LPS(lps, P, tamP);
	
    int j = 0; // j eh tamanho do meu match atual, ONDE EU ESTA PADRAO
    int i = 0; // posicao no texto
    while(i < tamT)
	{
        if(T[i] == P[j]) // match
		{
			j++;
			i++;
			if(j == tamP) // encontrei o padrao no texto na posicao (i-tamP) até i
			{
			   	//cout << "pule o episodio " << i-tamP+1 << endl;
			   	j = lps[j-1];
			   	return 1;
		   	}
		}
		else // mismatch
		{
			if(j != 0) // se ocorreu mismatch depois de j matchs
				j = lps[j-1];
			else // mismatch na comparacao da primeira letra
				i++;
		}
		
    }

    return 0;
}

int main(){
//    KMP ENCONTRA O PADRAO NO TXT
//    MAIOR PREFIXO QUE BATE COM O SUFIXO , QUE NAO SAO DO MSM TAMANHO

    string T; // T -> texto 
    int n; //numero de eps
    int x; // variavel auxiliar
    
    string cod; 
    cod = "mar";
      
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        getline(cin, T);
        x = kmp(T,cod,T.size(), cod.size());
        if(x == 1){
            cout << "pule o episodio " << i << endl;
        }   
    }
    return 0;
}