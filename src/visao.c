#include <stdio.h>
#include <stdlib.h>
#include "../includes/visao.h"
#include "../includes/utils.h"

#define MAX_TRANS 10

int fatorial(int n){
    int f;

    for(f = 1; n > 1; n--)
        f *= n;

    return f;
}

int npr(int n){
    int r = n;
    return fatorial(n)/fatorial(n-r);
}

void permuta(int n, int **matriz)
{   
    int a[n];
    int i, j, k, store;

    int linha, coluna;
    linha = 0;
    coluna = 0;

    for(i=0; i<n; i++)
        a[i] = i+1;

    for(i=1; i<=n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            store = a[j+1];
            a[j+1] = a[j];
            a[j] = store;
            for(k=0; k<n; k++){                
                matriz[linha][coluna] = a[k];
                linha++;
            }
            printf("\n");
            linha = 0;
            coluna++;
        }      
    }
}

// passar só o escalonamento e pegar o n_trans
int** cria_combinacoes(int n_trans, int n_visoes){  
   
    int **matriz;
    
    matriz = (int **)malloc(n_trans*sizeof(int*));
    for(int i = 0; i < n_trans; i++)
        matriz[i] = (int *)malloc(n_visoes*sizeof(int));

    permuta(n_trans, matriz);   

    for(int i = 0; i < n_trans; i++){
        for(int j = 0; j < n_visoes; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }  

    return matriz;
}

/*

int cria_visao(S, visao, int **matriz, int cont_visoes, int n_trans){    

    int cont_trans = 0;
    while(cont_trans < n_trans){
        int trans_vez = matrix[cont_trans][cont_visoes];

        transacao aux;            
      
        int cont = 0;            
        while(cont < S->TAMANHO){
            aux = S->lista_transacoes[cont];

            if(aux->id = trans_vez)
                break;
                
            cont++;
        }
        
        // teria q mudar o timestamp da transacao mas n vou fazer por enquanto

        while(aux->proxima != null)
        {
            insere_agendamento(aux, S);   
            aux = tran-proxima;  
        }
        cont_trans++;
    }

}

boolean analisa_visao(S, visao){

    int n_trans = S->qtd_transacoes;  

    // vetores cujo indice eh o numero da transacao e conteudo eh o atributo da op
    char atributos_read[10];
    char atributos_write[10];

    // marca ultimo write de cada transacao
    char ultimo_write

    int cont = 0;
    int ordem[10];
    
    bool eh_equi = true;

    while < n_trans e eh_equi == true   
    {
        pega primeira operacao
        
        se for write
        {
            atributos_write[transacao->id] = transacao->atr;

            ultimo_write[transacao->id] = 
        }
        se for read 
            atributos_read[transacao->id] = transacao->atr;
            // anda no vetor atributos_write procurando um com o mesmo atributo
            for(int i = 0; i < transacao->id; i++)
            {
                if atributos_write[i] = transacao->atr
                {
                    ordem[cont] = i;
                    ordem[cont+1] = transacao->id;

                    cont += 2;
                }
            }      
            
        vai pra proxima em timestamp
    }
}


int equivalente_por_visao(agendamento *S){
    //int n_trans = S->qtd_transacoes;  
    int n_visoes = npr(n_trans);
      
    int **matriz;
    
    matriz = (int **)malloc(n_trans*sizeof(int*));
    for(int i = 0; i < n_trans; i++)
        matriz[i] = (int *)malloc(n_visoes*sizeof(int));

    matriz = cria_combinacoes(S);    

    eh_equi = True;
    int cont_visoes = 0; 

    while(cont_visoes < n_visoes || eh_equi == True){
        agendamento *visao = malloc(sizeof(S)); 
        cria_agendamento(visao);

        cria_visao(S, visao, cont_visoes, n_trans);

        eh_equi = analisa_visao(S, visao);
        // aqui compara, retorna se he equivalente ou nao
        // se nao for, eh_equi fica false e para o loop       
    }

*/

    





