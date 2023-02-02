#include <stdio.h>
#include "../includes/visao.h"
#include "../includes/utils.h"

#define MAX_TRANS 10

int fatorial(int n){
    int f;

    for(f = 1; n > 1; n--)
        f *= n;

    return f;
}

int npr(int n, int r){
    return fatorial(n)/fatorial(n-r);
}

int permuta(int n, int **matriz)
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

int cria_combinacoes(agendamento *S, int **matriz, int n_trans, int n_visoes){
    
    permuta(n_trans, matriz);   

    for(int i = 0; i<n_trans;i++){
        for(int j = 0; j< n_visoes;j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }  

    return 1;
}
/*
int cria_visoes(agendamento *S){
    //int n_trans = S->qtd_transacoes;
    int n_trans = 3;
    int n_visoes = npr(n_trans, n_trans);
   
    int **matriz;

    matriz = (int **)malloc(n_trans*sizeof(int*));
    for(int i = 0; i < n_trans; i++)
        matriz[i] = (int *)malloc(n_visoes*sizeof(int));

    cria_combinacoes(S, matriz);

    

    int cont_visoes = 0; 

    while(cont_visoes < n_visoes){
        agendamento *visao = malloc(n_trans*sizeof(agendamento)); 
        cria_agendamento(visao);

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

            while()
            insere_agendamento(tran, S);


            


        }
       
    }

*/

    





