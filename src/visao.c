#include <stdio.h>
#include <stdlib.h>
#include "../includes/visao.h"
#include "../includes/utils.h"

#define MAX_TRANS 10

void imprime_matriz(int **matriz, int lin, int col)
{
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}


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
    int tamanho_agenda = a->tam;
    int cont_trans = 0;
    int cont = 0;
    int trans_vez;

    while(cont_trans < n_trans){
        trans_vez = matriz[cont_trans][cont_visoes];
       
        Transacao *aux = a->inicio;  

        cont = 0;

        while(cont < tamanho_agenda){    

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

int adiciona_vetor(int vetor[], int pos, int valor){
    int idx = 0;
    int cont_ordem = pos;

    while(idx < pos + 1){ 
        if(vetor[idx] == valor){
            return 1;
        }
        idx++;
    }

    vetor[pos] = valor;
    cont_ordem++;

    return cont_ordem;
}

int compara_vetor(int v_a[], int v_v[], int tam_a, int tam_v){
    
    for(int i = 0; i < tam_a; i++){
        if(v_a[i] != v_v[i])
            return 0;
    }
    return 1;
}

int vetor_unico_attrs(Agenda *a, int *vetor){   
    int tam = 0;

    Transacao *aux = a->inicio;
    int cont = 0;
    while(cont < a->tam){
        if(aux->atributo != 45){
            tam = adiciona_vetor(vetor, tam, aux->atributo);           
        } 
        cont++;       
        aux = aux->proximo;
    }   
    return tam;
}

int indice(int *vetor, int atributo, int tam_vetor){
    int i = 0;
    while(i < tam_vetor){
        if(vetor[i] == atributo){
            return i;
        }
        i++;
    }
}

int compara_vetores(int *ultima_a, int *ultima_v, int* atributos_unicos, int tam_vetor){
    int index = 0;
    while(index < tam_vetor){
        if(ultima_a[index] != ultima_v[index])
            return 0;
        index++;
    }

    return 1;
}

int teste_1(){


}

int teste_2(){
    
}

int analisa_visao(Agenda *a, Agenda *visao){

    int id_a, id_v;
    int n_trans = a->num_transacoes;
    int tamanho_agenda = a->tam;
    int ultima_a;
    int ultima_v;

    

    // cria duas matrizes para armazenar os atributos escritos e lidos para cada transação no escalonamento
    int escritas_a[n_trans+1][tamanho_agenda+1];
    int leituras_a[n_trans+1][tamanho_agenda+1];
    int escritas_v[n_trans+1][tamanho_agenda+1];
    int leituras_v[n_trans+1][tamanho_agenda+1];

    int cont_escrita_a[n_trans+1];
    int cont_leitura_a[n_trans+1];
    int cont_escrita_v[n_trans+1];
    int cont_leitura_v[n_trans+1];

    int ordem_trans_a[n_trans];
    int ordem_trans_v[n_trans];

    // inicializa matrizes
    for (int i = 0; i < n_trans+1; i++){

        cont_escrita_a[i] = 0;
        cont_leitura_a[i] = 0;

        cont_escrita_v[i] = 0;
        cont_leitura_v[i] = 0;

        ordem_trans_a[i] = 0;
        ordem_trans_v[i] = 0;

        for (int j = 0; j < tamanho_agenda+1; j++){
            escritas_a[i][j] = 0;
            leituras_a[i][j] = 0;

            escritas_v[i][j] = 0;
            leituras_v[i][j] = 0;
        }
    }

    // cria dois vetores para armazenar número de leituras e escritas por vetor
  
    Transacao *aux_a = a->inicio;
    Transacao *aux_v = visao->inicio;
    int cont = 0;
    // contabiliza operações e armazena a operação de cada transação
    while(cont < tamanho_agenda){     
        id_a = aux_a->identificador;
        id_v = aux_v->identificador;   
        
        if (aux_a->operacao == 'R'){              
            leituras_a[id_a][cont] = (int)aux_a->atributo;
            cont_leitura_a[id_a]++;

        }
        else if (aux_a->operacao == 'W'){           
            cont_escrita_a[id_a]++;
            escritas_a[id_a][cont] = (int)aux_a->atributo;
        }

        if (aux_v->operacao == 'R'){                       
            leituras_v[id_v][cont] = (int)aux_v->atributo;
            cont_leitura_v[id_v]++;
        }
        else if (aux_v->operacao == 'W'){   
            escritas_v[id_v][cont] = (int)aux_v->atributo;        
            cont_escrita_v[id_v]++;
        }

        aux_a = aux_a->proximo;
        aux_v = aux_v->proximo;
        cont++;
    }
     /* 
    printf("\t\tValor ascii das escritas em ordem - AGENDA ORIGINAL\n") ;
    printf("Timestamp: \t") ;
    for(int i = 1; i < tamanho_agenda+1;i++)
        printf("%d\t", i);
    printf("\n");
    for(int i = 1; i < n_trans+1; i++)
    {
        printf("Transacao %d:\t", i);
        for(int j = 0; j < tamanho_agenda; j++)
        {
            printf("%d\t", escritas_a[i][j]);
        }
        printf("\n");
    }
    
    
    printf("\t\tValor ascii das leituras em ordem - AGENDA ORIGINAL\n") ;
    printf("Timestamp: \t") ;
    for(int i = 1; i < tamanho_agenda+1;i++)
        printf("%d\t", i);
    printf("\n");
    for(int i = 1; i < n_trans+1; i++)
    {
        printf("Transacao %d:\t", i);
        for(int j = 0; j < tamanho_agenda; j++)
        {
            printf("%d\t", leituras_a[i][j]);
        }
        printf("\n");
    }
   
    printf("\t\tValor ascii das escritas em ordem - VISAO \n") ;
    printf("Timestamp: \t") ;
    for(int i = 1; i < tamanho_agenda+1;i++)
        printf("%d\t", i);
    printf("\n");
    for(int i = 1; i < n_trans+1; i++)
    {
        printf("Transacao %d:\t", i);
        for(int j = 0; j < tamanho_agenda; j++)
        {
            printf("%d\t", escritas_v[i][j]);
        }
        printf("\n");
    }

    printf("\t\tValor ascii das leituras em ordem - VISAO\n") ;
    printf("Timestamp: \t") ;
    for(int i = 1; i < tamanho_agenda+1;i++)
        printf("%d\t", i);
    printf("\n");
    for(int i = 1; i < n_trans+1; i++)
    {
        printf("Transacao %d:\t", i);
        for(int j = 0; j < tamanho_agenda; j++)
        {
            printf("%d\t", leituras_v[i][j]);
        }
        printf("\n");
    }
    */
           
    int cont_ordem_a = 0;
    int cont_ordem_v = 0;
    
    int atributo;
    int index = 1;
    int eh_equi = 1;

    while((index < n_trans + 1) && (eh_equi == 1)){   
        if(cont_leitura_a[index] != 0){ 
                    
            for(int j = 0; j < tamanho_agenda; j++){
                if(leituras_a[index][j] != 0){

                    //leitura espeficica
                    atributo = leituras_a[index][j];                

                    for(int k = 1; k < n_trans+1; k++){
                        if(k == index)                      
                            break;                        
                        else{                           
                            for(int l = 0; l < j; l++){
                                if(escritas_a[k][l] == atributo){                  
                                    printf("achei escrita do atributo %d em %d %d \n", atributo, k, l);
                                    cont_ordem_a = adiciona_vetor(ordem_trans_a, cont_ordem_a, k);                                                     
                                }
                            } 
                        }
                    }
                }
            }                 
        
        cont_ordem_a = adiciona_vetor(ordem_trans_a, cont_ordem_a, index);
        
        
        for(int j = 0; j < tamanho_agenda; j++){
                if(leituras_v[index][j] != 0){

                    //leitura espeficica
                    atributo = leituras_v[index][j];                   

                    for(int k = 1; k < n_trans+1; k++){
                        if(k == index)                      
                            break;                        
                        else{                           
                            for(int l = 0; l < j; l++){
                                if(escritas_v[k][l] == atributo){                                   
                                    cont_ordem_v = adiciona_vetor(ordem_trans_v, cont_ordem_v, k);                                                     
                                }
                            } 
                        }
                    }
                }
            }          
        
        cont_ordem_v = adiciona_vetor(ordem_trans_v, cont_ordem_v, index);    

        eh_equi = compara_vetor(ordem_trans_a, ordem_trans_v, cont_ordem_a, cont_ordem_v);             
        }

        index++;         
    }

    /*for(int i = 0; i < cont_ordem_a; i++)
        printf("%d ",ordem_trans_a[i]);
    printf("\n");

    for(int i = 0; i < cont_ordem_v; i++)
        printf("%d ",ordem_trans_v[i]);
    printf("\n");*/

    printf("teste 1 eh equi %d \n", eh_equi);

    int tam_vetor;
    int *atributos_unicos = malloc(MAX_TRANS*sizeof(int));
    tam_vetor = vetor_unico_attrs(a, atributos_unicos);

    /*for(int i = 0; i < tam_vetor; i++)
        printf("%d ",atributos_unicos[i]);
    printf("\n");*/
    
    
    int* vetor_ultima_a = calloc(tam_vetor, sizeof(int));    
    int* vetor_ultima_v = calloc(tam_vetor, sizeof(int));   
    int atributo_v;

    for(int j = 0; j < tamanho_agenda; j++){
        for(int i = 0; i < n_trans+1; i++){
            atributo = escritas_a[i][j];         
            atributo_v = escritas_v[i][j];  

            if(atributo != 0 && atributo != 45){
                int posicao = indice(atributos_unicos, atributo, tam_vetor+1);                

                if(j >= vetor_ultima_a[posicao]){
                    //printf("ultima escrita agenda de %d foi na transacao %d \n", atributos_unicos[posicao], i);
                    vetor_ultima_a[posicao] = i;                     
                }
                    
            } 

            if(atributo_v != 0 && atributo_v != 45){
                int posicao = indice(atributos_unicos, atributo_v, tam_vetor+1);                

                if(j >= vetor_ultima_v[posicao]){
                    //printf("ultima escrita visao de %d foi na transacao %d \n", atributos_unicos[posicao], i);
                    vetor_ultima_v[posicao] = i; 
                }                    
            }           
        }
    }

    eh_equi = compara_vetores(vetor_ultima_a, vetor_ultima_v, atributos_unicos, tam_vetor);     
    printf("teste 2 eh equi %d \n", eh_equi);

    return eh_equi;
}

    /*    // valida se a escrita de um atributo for a última operação da transação
    for (int i = 0; i < n_trans; i++)
    {
        for (int j = 0; j < cont_escrita_a[i]; j++)
        {
            int atributo = escritas_a[i][j];
        i 
            for (int k = 0; k < n_trans; k++)
            {
                // garante que não seja considerada as operações de escrita da transação i
                if (k == i)
                    continue;
                for (int l = 0; l < cont_escrita_a[k]; l++)
                {
                    if (escritas_a[k][l] == atributo)
                        return "NV";
                }
            }
        }
    } 
    */

int equivalente_por_visao(Agenda *a){
    
    int eh_equi;

    int n_trans = a->num_transacoes;
    int n_visoes = npr(n_trans);

    int **matriz;      

    matriz = cria_combinacoes(n_trans, n_visoes);   

    //imprime_matriz(matriz, n_trans, n_visoes);

    eh_equi = 0;

    int cont_visoes = 0; 

    while(cont_visoes < n_visoes-1 /*|| eh_equi == 0*/){
        Agenda *visao = cria_agenda();

        cria_visao(a, visao, matriz, cont_visoes, n_trans);

        visao->lista_ids_unicos = a->lista_ids_unicos;
        visao->num_transacoes = a->num_transacoes;
       
        imprime(visao);
        printf("\n");

       
        /*for(int i = 0; i < tam_vetor+1; i++)
            printf("%d ",atributos_unicos[i]);
        printf("\n");*/

        eh_equi = analisa_visao(a, visao); 
        // aqui compara, retorna se he equivalente ou nao
        
        cont_visoes++; 
    }    

    return eh_equi;
}


    





