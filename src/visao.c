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

    /*for(int i = 0; i < n_trans; i++){
        for(int j = 0; j < n_visoes; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    } */ 

    return matriz;
}

void imprime(Agenda *a)
{
    Transacao *aux = a->inicio;
        
    printf("\n\n ---- Informacoes da visao --- \n");
    printf("Tamanho: %d\nNum transacoes: %d \n", a->tam, a->num_transacoes);
    imprime_ids(a);
    printf("\nOrdem de transcoes processadas: ");

    for(int i = 0; i < a->tam; i++){
        printf("%d ", aux->identificador);
        aux = aux->proximo;
    }

    printf("\n");
}

void cria_visao(Agenda *a, Agenda *visao, int **matriz, int cont_visoes, int n_trans){    

    int cont_trans = 0;
    int cont = 0;
    int trans_vez;

    while(cont_trans < n_trans){
        trans_vez = matriz[cont_trans][cont_visoes];
       
        Transacao *aux = a->inicio;  

        cont = 0;

        while(cont < a->tam){    

            if(aux->identificador == trans_vez)
            {               
                Transacao *teste = cria_transacao(aux->tempo_chegada, aux->identificador, aux->operacao, aux->atributo);
                adiciona_info_agenda(teste, visao);           
            }      
        
            aux = aux->proximo;               
            cont ++;
        }
        
        // teria q mudar o timestamp da transacao mas n vou fazer por enquanto       
        cont_trans++;

        free(aux);      
    }   
}
/*

boolean analisa_visao(S, visao){

    int id;
    int n_trans = S->qtd_transacoes;  

    // cria duas matrizes para armazenar os atributos escritos e lidos para cada transação no escalonamento
    int writes[qtd_transacoes][num_operacoes];
    int reads[qtd_transacoes][num_operacoes];

    // inicializa matrizes
    for (int i = 0; i < qtd_transacoes; i++)
    {
        for (int j = 0; j < num_operacoes; j++)
        {
            writes[i][j] = 0;
            reads[i][j] = 0;
        }
    }

    // cria dois vetores para armazenar número de leituras e escritas por vetor
    int *cont_escrita = calloc(MAX_TRANSACTIONS, sizeof(int));
    int *cont_leitura = calloc(MAX_TRANSACTIONS, sizeof(int));

    // contabiliza operações e armazena a operação de cada transação
    for (int i = 0; i < num_operacoes; i++)
    {
        id = transacoes[i].identificador;
        
        if (transacoes[i].operacao == 'R')
        {
            reads[id][cont_leitura[id]] = transacoes[i].atributo;
            cont_leitura[id]++;
        }
        else if (transacoes[i].operacao == 'W')
        {
            writes[id][cont_escrita[id]] = transacoes[i].atributo;
            cont_escrita[id]++;
        }
    }

    // verifica se para cada leitura de atributo de Ti já foi escrito por Tj
    for (int i = 0; i < qtd_transacoes; i++)
    {
        for (int j = 0; j < cont_leitura[i]; j++)
        {
            int atributo = reads[i][j];
            int escrito = 0;
            for (int k = 0; k < qtd_transacoes; k++)
            {
                // garante que não seja considerada as escritas da própria transação Ti
                if (k == i)
                    continue;
                for (int l = 0; l < cont_escrita[k]; l++)
                {
                    if (writes[k][l] == atributo)
                    {
                        escrito = 1;
                        break;
                    }
                }
                if (escrito)
                    // salvar para comparar com a visao
            }
            if (!escrito)
                // n precisa fazer nada acho
        }
    }

    // valida se a escrita de um atributo for a última operação da transação
    for (int i = 0; i < qtd_transacoes; i++)
    {
        for (int j = 0; j < cont_escrita[i]; j++)
        {
            int atributo = writes[i][j];
            for (int k = 0; k < qtd_transacoes; k++)
            {
                // garante que não seja considerada as operações de escrita da transação i
                if (k == i)
                    continue;
                for (int l = 0; l < cont_escrita[k]; l++)
                {
                    if (writes[k][l] == atributo)
                        return "NV";
                }
            }
        }
    } 













    // testando outro jeito de fazer:
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

*/



int equivalente_por_visao(Agenda *a){
    
    int eh_equi;

    int n_trans = a->num_transacoes;
    int n_visoes = npr(n_trans);

    int **matriz;
    
    matriz = (int **)malloc(n_trans*sizeof(int*));
    for(int i = 0; i < n_trans; i++)
        matriz[i] = (int *)malloc(n_visoes*sizeof(int));    

    matriz = cria_combinacoes(n_trans, n_visoes);   

    eh_equi = 1;

    int cont_visoes = 0; 

    while(cont_visoes < n_visoes /* || eh_equi == 1*/){
        Agenda *visao = cria_agenda();

        cria_visao(a, visao, matriz, cont_visoes, n_trans);

        visao->lista_ids_unicos = a->lista_ids_unicos;
        visao->num_transacoes = a->num_transacoes;
       
        imprime(visao);

        //eh_equi = analisa_visao(a, visao);
        // aqui compara, retorna se he equivalente ou nao
        // se nao for, eh_equi fica false e para o loop   
  
        cont_visoes++; 
    }
    
    return eh_equi;
}


    





