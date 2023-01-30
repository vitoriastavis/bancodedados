#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../includes/agendamento.h"


/* Cria uma agendamento vazia */
int cria_agendamento(agendamento * S){
    S->inicio = NULL;
    S->tamanho = 0;   
    return 1;
}

/* Retorna 1 se a agendamento está vazia e zero caso contrário; */
int agendamento_vazio(agendamento *S){
    if ((S->inicio == NULL) && (S->tamanho == 0))
        return 1;
    return 0;
}

/* Remove todos os elementos da agendamento e aponta ela para NULL */
void destroi_agendamento(agendamento *S){
    transacao *aux;
 
    if(agendamento_vazio(l)){
        printf("não destruida: agendamento vazia\n");
    }

    while (S->inicio != NULL){
        aux = S->inicio;
        S->inicio = aux->prox;
        S->tamanho--;
        free(aux);
    }        
}

/* Insere o x no inı́cio da lista;
   Retorna 1 se a operação foi bem sucedida e zero caso contrario */
int insere_inicio_lista(int x, agendamento *S){
    transacao *aux;
    transacao *novo;  
    
    /* faz malloc e testa */
    novo = malloc(sizeof(transacao));
    if (novo == NULL){
        printf("Erro na alocação da memória");
        exit(0);
    }

    /* monta o novo nodo */
    aux = S->inicio;
    novo->dado = x;
    novo->prox = aux;
    S->inicio = novo;
    S->tamanho++;    
    return 1;
}

/* Insere o elemento x no final da lista; 
   Retorna 1 se a operação foi bem sucedida e zero caso contrário */
int insere_fim_lista(int x, agendamento *S){ 
    transacao *novo;
    transacao *posicao;    

    /* faz malloc e o testa */
    novo = malloc(sizeof(transacao));
    if (novo == NULL){
        printf("Erro na alocação da memória");
        exit(0);
    }  

    if (lista_vazia(l)){
        insere_inicio_lista(x, l);
        free(novo); 
        return 1;
    }

    /* monta o novo nodo */
    novo->dado = x;
    novo->prox = NULL;

    posicao = S->inicio; 
   
    /* vai até a penúltima posição */
    while (posicao->prox != NULL){
        posicao = posicao->prox;
    } 
    
    /* adiciona o nodo */
    posicao->prox = novo;

    S->tamanho++; 

    return 1;  
}

/* Insere x na lista de maneira que ela fique em ordem crescente
   Retorna 1 se a operação foi bem sucedida e zero caso contrário 
   
    ******** AJUSTAR PARA ORDERNAR POR ID DA TRANSACAO ************

   */
int insere_ordenado_lista(int x, agendamento *S){
    transacao *novo;
    transacao *posicao;   

    /* faz malloc e o testa */
    novo = malloc(sizeof(transacao));
    if (novo == NULL){
        printf("Erro na alocação da memória");
        exit(0);
    }  

    if (lista_vazia(l)){
        insere_inicio_lista(x, l); 
        free(novo);
        return 1;
    }    

    /* monta o novo nodo */
    novo->dado = x;
    novo->prox = NULL;

    /* vai até a posição */
    posicao = S->inicio;

    if (posicao->dado-> x){
        insere_inicio_lista(x, l);
        free(novo); 
        return 1;
    }

    while ((posicao->prox != NULL) && (posicao->prox->dado < x)){
        posicao = posicao->prox;
    }

    /* adiciona o nodo */
    novo->prox = posicao->prox;
    posicao->prox = novo;

    S->tamanho++;

    return 1;  
}

/* Imprime os elementos da lista, do inı́cio ao final.
   Se ela for vazia não imprime nada*/
void imprime_lista(agendamento *S){
    transacao *posicao;   

    if (lista_vazia(l)){ 
        return;
    }

    posicao = S->inicio;  
    printf("tam: %d -> ", S->tamanho);   
    printf("%d ", posicao->dado);
    while (posicao->prox != NULL){        
       posicao = posicao->prox; 
       printf("%d ", posicao->dado);                   
    }
    printf("\n");
}

/* Remove o 1o elemento da lista e o retorna em *item;
   Retorna 1 se a operação foi bem sucedida e zero caso contrário */
int remove_primeiro_lista(int *item, agendamento *S){    
    transacao * aux;
    
    if (lista_vazia(l))
        return 0;    

    aux = S->inicio;
    *item = aux->dado;
    S->inicio = S->inicio->prox; /* tira o primeiro dado */
    free(aux);
    S->tamanho--;        
    
    if (item == NULL)
        return 0;
    return 1;          
}   

/* Remove o último elemento da lista e o retorna;
   Retorna 1 se a operação foi bem sucedida e zero caso contrário */
int remove_ultimo_lista(int *item, agendamento *S){
    transacao *aux;
    transacao *remover;
    int i;

    if (lista_vazia(l))
        return 0;

    aux = S->inicio;

    if (S->tamanho == 1){
        remove_primeiro_lista(item, l); 
        return 1;
    }

    /* anda ate a penúltima posição */
    for (i = 1; i < S->tamanho-1; i++){
        aux = aux->prox;
    }    

    *item = aux->prox->dado;
    remover = aux->prox;
    aux->prox = NULL; /* tira o ultimo dado */
    free(remover);    
    S->tamanho--;

    if (item == NULL)
        return 0;
    return 1; 
}

/* Se o elemento chave existir na lista, o retorna em *item;
   Retorna 1 se a operação foi bem sucedida e zero caso contrário */
int remove_item_lista(int chave, int * item, agendamento *S){
    transacao * aux;
    transacao * remover;       

    if (lista_vazia(l)){
        printf("lista vazia");
        return 0;       
    }
    if (!pertence_lista(chave, l)){
        printf("Nao removido: elemento nao encontrado.\n");       
        return 0;
    }

    aux = S->inicio;   
    if (aux->dado == chave){       
        remove_primeiro_lista(item, l);
        return 1;
    }
    else{
        /*procura a posição anterior à da chave */
        while (aux->prox != NULL){
            aux = aux->prox;              
            if (aux->dado == chave){
                *item = aux->prox->dado;
                remover = aux->prox;   
                aux->prox = aux->prox->prox; /* tira o dado */
                S->tamanho--;
                free(remover);     
                return 1;
            }
            if ((aux->prox->dado == chave) && (aux->prox->prox == NULL)){
                remove_ultimo_lista(item, l);                
                return 1;
            }                
        }            
    }
    return 1;          
}

/* Retorna 1 se a chave existe na lista, caso contrário retorna zero */
int pertence_lista(int chave, agendamento *S){
    transacao * aux;
    aux = S->inicio;   

    while (aux != NULL){
        if (aux->dado == chave)
            return 1;
        aux = aux->prox;
    }
    return 0;
} 

/* Cria uma nova lista m contendo uma cópia exata da lista l.
   Retorna 1 se a operação foi bem sucedida e zero caso contrário */
int copia_lista(agendamento *S, agendamento * m){
    transacao * aux;

    aux = S->inicio;

    insere_fim_lista(aux->dado, m);
    while (aux->prox != NULL){        
        aux = aux->prox;
        insere_fim_lista(aux->dado, m);
    }  
    return 1;     
}
