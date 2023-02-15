#include <stdio.h>
#include <stdlib.h>
#include "../includes/equivalente_visao.h"

#define MAX_TRANS 50

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

int npr(int n)
{
    int r = n;
    
    return fatorial(n)/fatorial(n-r);
}

//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//function to print the array
void printarray(int arr[], int size, int** matriz, int coluna)
{
    int i;
    for(i=0; i<size; i++)
    {
        matriz[i][coluna] = arr[i];
        //printf("%d\t",arr[i]);
    }
    //printf("\n");
}

void permuta(int* ids_unicos, int start, int end, int** matriz, int *coluna)
{
    if(start==end)
    {
        printarray(ids_unicos, end+1, matriz, *coluna);
        (*coluna)++;
        return;
    }

    int i;

    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((ids_unicos+i), (ids_unicos+start));
        //fixing one first digit and calling permutation on the rest of the digits
        permuta(ids_unicos, start+1, end, matriz, coluna);
        swap((ids_unicos+i), (ids_unicos+start));
    }
}


int** cria_combinacoes(int n_trans, int n_visoes, int* ids_unicos)
{  
    /* Inicializa matriz */
    int **matriz;
    
    matriz = (int **)malloc(n_trans*sizeof(int*));
    for(int i = 0; i < n_trans; i++)
        matriz[i] = (int *)malloc(n_visoes*sizeof(int));

    /* Permutacao do n de transicoes e guardar combinacoes na matriz*/
    //permuta(n_trans, n_visoes, matriz, ids_unicos); 
    int coluna = 0;
    permuta(ids_unicos, 0, n_trans-1, matriz, &coluna);

    return matriz;
}

void imprime(Agenda *a)
{
    Transacao *aux = a->inicio;
        
    printf("---- Informacoes da visao --- \n");
    printf("Tamanho: %d\nNum transacoes: %d \n", a->tam, a->num_transacoes);
    imprime_ids(a);
    printf("\nOrdem de transcoes processadas: ");

    for(int i = 0; i < a->tam; i++){
        printf("%d ", aux->identificador);
        aux = aux->proximo;
    }
    printf("\n");    
}

void cria_visao(Agenda *a, Agenda *visao, int **matriz, int cont_visoes, int n_trans)
{    
    int tam_agenda = a->tam;
    int cont_trans = 0;
    int cont = 0;
    int trans_vez;

    while(cont_trans < n_trans)
    {
        trans_vez = matriz[cont_trans][cont_visoes];
       
        Transacao *aux = a->inicio;  

        cont = 0;

        while(cont < tam_agenda)
        {    

            if(aux->identificador == trans_vez)
            {               
                Transacao *teste = cria_transacao(aux->tempo_chegada, aux->identificador, aux->operacao, aux->atributo);
                adiciona_info_agenda(teste, visao);           
            }      
        
            aux = aux->proximo;               
            cont ++;
        }              
        cont_trans++;         
    }   
}

int add_vetor_unico(int vetor[], int pos, int valor)
{
    int idx = 0;
    int tamanho = pos;

    /* Anda pelo vetor buscando posicao para inserir ou nao, se ja existe o valor no vetor*/
    while(idx < pos + 1){ 
        if(vetor[idx] == valor)
        {
            return 1;
        }
        idx++;
    }

    /* Insere o valor e aumenta o tamanho*/
    vetor[pos] = valor;
    tamanho++;

    return tamanho;
}

int vetor_unico_attrs(Agenda *a, int *vetor)
{   
    int tam = 0;

    Transacao *aux = a->inicio;
    int cont = 0;

    /* Anda pela agenda adicionando os atributos unicos */
    while(cont < a->tam){
        if(aux->atributo != 45) /* Se nao é o - do commit */
        {
            tam = add_vetor_unico(vetor, tam, aux->atributo);           
        } 
        cont++;       
        aux = aux->proximo;
    }   
    return tam;
}

int indice_vetor_unico(int *vetor, int atributo, int tam_vetor)
{
    int i = 0;

    /* Anda pelo vetor procurando o atributo */
    while(i < tam_vetor)
    {
        if(vetor[i] == atributo)
        {
            /* Retorna indice */
            return i;
        }
        i++;
    }

    /* -1 se nao foi encontrado */
    return -1;
}

int compara_vetores(int v_a[], int v_v[], int tam_a, int tam_v)
{
    if(tam_a != tam_v)
        return 0;

    /*  Anda pelo vetor comparando com o outro */
    for(int i = 0; i < tam_a; i++)
    {
        if(v_a[i] != v_v[i])
            return 0;
    }
    return 1;
}

int teste_1(int n_trans, int tam_agenda, int** leituras_a, int** escritas_a, int* cont_leitura_a,
            int** leituras_v, int** escritas_v, int menor_id)
            {
    
    int tam_vetor_a = 0;
    int tam_vetor_v = 0;
    
    int atributo;      /* Atributo a ser analisado */
    int indice = 1;      /* Indice para andar pelas transacoes */
    int eh_equi = 1;    
        
    /* Vetores para guardar ordem das transacoes de acordo com o primeiro teste */
    int *ordem_trans_a = calloc(n_trans, sizeof(int));
    int *ordem_trans_v = calloc(n_trans, sizeof(int));  

    /* Anda pelas transacoes ate a ultima ou ate eh_equi ser falso*/
    while((indice < n_trans + 1) && (eh_equi == 1))
    {   
        /* Continua apenas se aquela transacao fez leituras */
        if(cont_leitura_a[indice] != 0)
        { 
            /* Primeiro analisando a agenda original */        
            for(int j = 0; j < tam_agenda; j++)
            {
                /* Se houve uma leitura */
                if(leituras_a[indice][j] != 0)
                {
                    /* Pega atributo lido */
                    atributo = leituras_a[indice][j];                

                    for(int k = 1; k < n_trans+1; k++)
                    {
                        /* Continua se escrita nao for a mesma transacao da leitura*/
                        if(k != indice){                                                   
                            for(int l = 0; l < j+1; l++)
                            {
                                /* Anda pela matriz de escritas, se for igual ao atributo adiciona no vetor */
                                if(escritas_a[k][l] == atributo)
                                {     
                                    tam_vetor_a = add_vetor_unico(ordem_trans_a, tam_vetor_a, k);                                                     
                                }
                            } 
                        }
                    }
                }
            }                 
        /* Adiciona transacao da leitura ao vetor da ordem */
        tam_vetor_a = add_vetor_unico(ordem_trans_a, tam_vetor_a, indice);      
        
        
        /* Agora analisando a visao */  
        for(int j = 0; j < tam_agenda; j++)
        {
                /* Se houve uma leitura */
                if(leituras_v[indice][j] != 0)
                {
                    /* Pega atributo lido */
                    atributo = leituras_v[indice][j]; 

                    for(int k = 1; k < n_trans+1; k++)
                    {
                        /* Continua se escrita nao for a mesma transacao da leitura*/
                        if(k != indice){                           
                            for(int l = 0; l < j; l++)
                            {
                                /* Anda pela matriz de escritas, se for igual ao atributo adiciona no vetor */
                                if(escritas_v[k][l] == atributo)
                                {       
                                    tam_vetor_v = add_vetor_unico(ordem_trans_v, tam_vetor_v, k);                                                     
                                }
                            } 
                        }
                    }
                }
            }          
        /* Adiciona transacao da leitura ao vetor da ordem */
        tam_vetor_v = add_vetor_unico(ordem_trans_v, tam_vetor_v, indice);    

        /* Compara vetores */
        eh_equi = compara_vetores(ordem_trans_a, ordem_trans_v, tam_vetor_a, tam_vetor_v);             
        }

        indice++;         
    }

    free(ordem_trans_a);
    free(ordem_trans_v);

    return eh_equi;
}

int teste_2(int tam_vetor, int tam_agenda, int n_trans, int** escritas_a, int** escritas_v, int* atributos_unicos){
    /* Guarda transacao da ultima escrita dos atributos*/ 
    int* ultimas_a = calloc(tam_vetor, sizeof(int));   
    int* ultimas_v = calloc(tam_vetor, sizeof(int));   

    int atributo_v;
    int atributo_a;

    int eh_equi2;

    /* Anda pela matriz de escritas da original e da visao*/
    for(int j = 0; j < tam_agenda; j++)
    {
        /* Acesso por colunas para pegar a ultima */
        for(int i = 0; i < n_trans+1; i++)
        {
            /* Pega atributos escritos */
            atributo_a = escritas_a[i][j];         
            atributo_v = escritas_v[i][j];  
            int ultimo_a = 0;
            int ultimo_v = 0;

            /* Se atributo foi lido e nao eh o - na original */
            if(atributo_a != 0 && atributo_a != 45)
            {
                
                /* Pega posicao desse atributo no vetor de atributos unicos */                
                int posicao = indice_vetor_unico(atributos_unicos, atributo_a, tam_vetor+1);                
             
                /* Se aquela escrita aconteceu depois da outra do atributo */
                if(j >= ultimo_a)
                {
                    /* Guarda a transacao no vetor */
                    ultimas_a[posicao] = i; 
                    ultimo_a = j;                    
                }                    
            } 

            /* Se atributo foi lido e nao eh o - na visao */
            if(atributo_v != 0 && atributo_v != 45)
            {
                /* Pega posicao desse atributo no vetor de atributos unicos */
                int posicao = indice_vetor_unico(atributos_unicos, atributo_v, tam_vetor+1);                

                /* Se aquela escrita aconteceu depois da outra do atributo */
                if(j >= ultimo_v)
                {
                    /* Guarda a transacao no vetor */
                    ultimas_v[posicao] = i;
                    ultimo_v = j; 
                }                    
            }           
        }
    }

    eh_equi2 = compara_vetores(ultimas_a, ultimas_v, tam_vetor, tam_vetor);      

    /*free(ultimas_a);
    free(ultimas_v);*/

    return eh_equi2;
}

int menor_identificador(int *ids_unicos, int tam)
{
    int index = 0;
    int menor_id = ids_unicos[tam-1];
    while(index < tam)
    {
        if(ids_unicos[index] < menor_id)
        {
            menor_id = ids_unicos[index];
        }
        index++;
    }

    return menor_id-1;
}

int analisa_visao(Agenda *a, Agenda *visao)
{
    int id_a, id_v;
    int n_trans = a->num_transacoes;
    int tam_agenda = a->tam;
   
    int eh_equi1, eh_equi2;

    int menor_id = menor_identificador(a->lista_ids_unicos, n_trans);   
   
    /* cria matrizes para armazenar os atributos escritos e lidos para cada transacao
       sendo 'a' para a agenda original e 'v' para a visao  */
    int **escritas_a = calloc(n_trans+1, sizeof(int*));
    int **leituras_a = calloc(n_trans+1, sizeof(int*));
    int **escritas_v = calloc(n_trans+1, sizeof(int*));
    int **leituras_v = calloc(n_trans+1, sizeof(int*));

    /* cria vetores para armazenar o numero de escritas e leituras 
       sendo 'a' para a agenda original e 'v' para a visao  */
    int *cont_escrita_a = calloc(n_trans+1, sizeof(int));
    int *cont_leitura_a = calloc(n_trans+1, sizeof(int));
    int *cont_escrita_v = calloc(n_trans+1, sizeof(int));
    int *cont_leitura_v = calloc(n_trans+1, sizeof(int)); 
  
    /* inicializa matrizes  */
    for (int i = 0; i < n_trans+1; i++)
    {      
        escritas_a[i] = calloc(tam_agenda, sizeof(int*));
        leituras_a[i] = calloc(tam_agenda, sizeof(int*));
        escritas_v[i] = calloc(tam_agenda, sizeof(int*));
        leituras_v[i] = calloc(tam_agenda, sizeof(int*));
    }

    /* Auxiliares para andar pela agenda e pela visao */
    Transacao *aux_a = a->inicio;
    Transacao *aux_v = visao->inicio;
    int cont = 0;    
    
    /* contabiliza operações e armazena a operação de cada transação */
    while(cont < tam_agenda)
    {     
        if(aux_v==NULL)
            break;

        id_a = aux_a->identificador;
        id_v = aux_v->identificador;      
 
        if (aux_a->operacao == 'R')
        {                      
            leituras_a[id_a - menor_id][cont] = (int)aux_a->atributo;           
            cont_leitura_a[id_a - menor_id]++;    

        }
        else if (aux_a->operacao == 'W')
        {                   
            cont_escrita_a[id_a - menor_id]++;
            escritas_a[id_a - menor_id][cont] = (int)aux_a->atributo;
        }

        if (aux_v->operacao == 'R')
        {                     
            leituras_v[id_v - menor_id][cont] = (int)aux_v->atributo;
            cont_leitura_v[id_v - menor_id]++;
        }
        else if (aux_v->operacao == 'W')
        {   
            escritas_v[id_v - menor_id][cont] = (int)aux_v->atributo;        
            cont_escrita_v[id_v - menor_id]++;
        }

        aux_a = aux_a->proximo;
        aux_v = aux_v->proximo;
        cont++;       
    }   

    /* Realiza primeiro teste */
    eh_equi1 = teste_1(n_trans, tam_agenda, leituras_a, escritas_a, cont_leitura_a, leituras_v, escritas_v, menor_id);
   
    /* Inicializa e preenche vetor de atributos unicos da agenda */
    int tam_vetor;
    int *atributos_unicos = malloc(MAX_TRANS*sizeof(int));
    tam_vetor = vetor_unico_attrs(a, atributos_unicos);  
    
    /* Realiza segundo teste */
    eh_equi2 = teste_2(tam_vetor, tam_agenda, n_trans, escritas_a, escritas_v, atributos_unicos); 
   
    /* Testa se foi equivalente para os dois testes, se sim eh equivalente */
    int eh_equi;
    if(eh_equi1 && eh_equi2)
        eh_equi = 1;
    else
        eh_equi = 0;        

    /*free(cont_escrita_a);
    free(cont_leitura_a);
    free(cont_escrita_v);
    free(cont_leitura_v); 

    for (int i = 0; i < n_trans+1; i++)
    {      
        free(escritas_a[i]);
        free(leituras_a[i]);
        free(escritas_v[i]);
        free(leituras_v[i]);
    }
    free(escritas_a);
    free(leituras_a);
    free(escritas_v);
    free(leituras_v);

    free(atributos_unicos);*/

    return eh_equi;
}

int eh_equivalente(Agenda *a)
{    
    int eh_equi = 0;
    int n_trans = a->num_transacoes;
    int n_visoes = npr(n_trans);
    
    /* Matriz para guardar as combinacoes possiveis para as visoes */
    int **matriz;   
    matriz = cria_combinacoes(n_trans, n_visoes, a->lista_ids_unicos); 
   
    //imprime_matriz(matriz, n_trans, n_visoes);

    int cont_visoes = 0; 

    /* Cria uma visao, preenche ela, analisa
        Se a agenda original for equivalente a visao criada, sai do loop
        Se nao, continua */
    while(cont_visoes < n_visoes && eh_equi == 0)
    {
        Agenda *visao = cria_agenda();        
  
        cria_visao(a, visao, matriz, cont_visoes, n_trans);      
     
        //imprime(visao);

        visao->lista_ids_unicos = a->lista_ids_unicos;
        visao->num_transacoes = a->num_transacoes;     
             
        /* Compara agenda com visao    */
        eh_equi = analisa_visao(a, visao);   
           
        cont_visoes++; 
        free(visao);
    }    
    
    for(int i = 0; i < n_trans; i++)
        free(matriz[i]);
    free(matriz);

    return eh_equi;
}


    





