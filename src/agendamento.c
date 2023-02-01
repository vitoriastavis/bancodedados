#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../includes/agendamento.h"

/* Cria um agendamento vazio */
int cria_transacao(transacao *t){
    t->t_chegada = 0;
    t->id = 0;
    t->operacao = "";
    t->atributo = "";
    t->prox_tempo = NULL;
    t->prox_op = NULL;
    t->ant_tempo = NULL;
    t->ant_op = NULL; 
    return 1;
}

int imprime_transacao(transacao *t){
    #ifdef DEBUG
            printf("\nImprimir t\n");        
    #endif
    printf("%d %d %c %c\n", t->t_chegada, t->id, t->operacao, t->atributo);

    return 1;
}

/* Cria um agendamento vazio */
int cria_agendamento(agendamento *S){
    S->inicio = NULL;
    S->tamanho = 0;   

    return 1;
}

/* Retorna 1 se a agendamento está vazio e zero caso contrário; */
int agendamento_vazio(agendamento *S){
    if ((S->inicio == NULL) && (S->tamanho == 0))
        return 1;
    return 0;
}

/* Remove todos os elementos doagendamento e aponta ela para NULL */
void destroi_agendamento(agendamento *S){
    transacao *aux;
 
    if(agendamento_vazio(S)){
        printf("não destruida: agendamento vazio\n");
    }

    while (S->inicio != NULL){
        aux = S->inicio;
        S->inicio = aux->prox;
        S->tamanho--;
        free(aux);
    }        
}

/* Insere a transacao no fim do agendamento;
   Retorna 1 se a operação foi bem sucedida e zero caso contrario */
int insere_agendamento(transacao *t_nova, agendamento *S){ 
    transacao *aux;

    if(!S || !t_nova)
        return 0;

    if(agendamento_vazio(S))
        S->inicio = t_nova;
    else{
        aux = S->inicio;

        while(aux->prox != NULL)
            aux = aux->prox;
        
        aux->prox = t_nova;
    } 

    S->tamanho++; 

    return 1;    
}


/* Insere x na agendamento de maneira que ela fique em ordem crescente
   Retorna 1 se a operação foi bem sucedida e zero caso contrário 
   
    ******** AJUSTAR PARA ORDERNAR POR ID doTRANSACAO ************

  

   
int insere_ordenado_agendamento(int x, agendamento *S){
    transacao *novo;
    transacao *posicao;   

    // faz malloc e o testa 
    novo = malloc(sizeof(transacao));
    if (novo == NULL){
        printf("Erro na alocação domemória");
        exit(0);
    }  

    if (agendamento_vazio(l)){
        insere_inicio_agendamento(x, l); 
        free(novo);
        return 1;
    }    

    // monta o novo nodo 
    novo->dado = x;
    novo->prox = NULL;

    // vai até a posição 
    posicao = S->inicio;

    if (posicao->dado-> x){
        insere_inicio_agendamento(x, l);
        free(novo); 
        return 1;
    }

    while ((posicao->prox != NULL) && (posicao->prox->dado < x)){
        posicao = posicao->prox;
    }

    // adiciona o nodo 
    novo->prox = posicao->prox;
    posicao->prox = novo;

    S->tamanho++;

    return 1;  
}

 */

/* Imprime os elementos doagendamento, do inı́cio ao final.
   Se ela for vazio não imprime nada*/
void imprime_agendamento(agendamento *S){
    transacao *posicao;   

    if (agendamento_vazio(S)){ 
        return;
    }

    posicao = S->inicio;  

    printf("tam: %d \n", S->tamanho);   
    imprime_transacao(posicao);

    while (posicao->prox != NULL){        
        posicao = posicao->prox; 
        imprime_transacao(posicao); 
    }
    printf("\n");
}

/* Remove o 1o elemento doagendamento e o retorna em *item;
   Retorna 1 se a operação foi bem sucedida e zero caso contrário 
int remove_primeiro_agendamento(int *item, agendamento *S){    
    transacao * aux;
    
    if (agendamento_vazio(l))
        return 0;    

    aux = S->inicio;
    *item = aux->dado;
    S->inicio = S->inicio->prox; // tira o primeiro dado
    free(aux);
    S->tamanho--;        
    
    if (item == NULL)
        return 0;
    return 1;          
}   
*/

/* Remove o último elemento doagendamento e o retorna;
   Retorna 1 se a operação foi bem sucedida e zero caso contrário 
int remove_ultimo_agendamento(int *item, agendamento *S){
    transacao *aux;
    transacao *remover;
    int i;

    if (agendamento_vazio(l))
        return 0;

    aux = S->inicio;

    if (S->tamanho == 1){
        remove_primeiro_agendamento(item, l); 
        return 1;
    }

    // anda ate a penúltima posição 
    for (i = 1; i < S->tamanho-1; i++){
        aux = aux->prox;
    }    

    *item = aux->prox->dado;
    remover = aux->prox;
    aux->prox = NULL; // tira o ultimo dado 
    free(remover);    
    S->tamanho--;

    if (item == NULL)
        return 0;
    return 1; 
}
*/

/* Se o elemento chave existir na agendamento, o retorna em *item;
   Retorna 1 se a operação foi bem sucedida e zero caso contrário 
int remove_item_agendamento(int chave, int * item, agendamento *S){
    transacao * aux;
    transacao * remover;       

    if (agendamento_vazio(l)){
        printf("agendamento vazio");
        return 0;       
    }
    if (!pertence_agendamento(chave, l)){
        printf("Nao removido: elemento nao encontrado.\n");       
        return 0;
    }

    aux = S->inicio;   
    if (aux->dado == chave){       
        remove_primeiro_agendamento(item, l);
        return 1;
    }
    else{
        // procura a posição anterior à da chave
        while (aux->prox != NULL){
            aux = aux->prox;              
            if (aux->dado == chave){
                *item = aux->prox->dado;
                remover = aux->prox;   
                aux->prox = aux->prox->prox; // tira o dado
                S->tamanho--;
                free(remover);     
                return 1;
            }
            if ((aux->prox->dado == chave) && (aux->prox->prox == NULL)){
                remove_ultimo_agendamento(item, l);                
                return 1;
            }                
        }            
    }
    return 1;          
}

*/

/* Retorna 1 se a chave existe na agendamento, caso contrário retorna zero 
int pertence_agendamento(int chave, agendamento *S){
    transacao * aux;
    aux = S->inicio;   

    while (aux != NULL){
        if (aux->dado == chave)
            return 1;
        aux = aux->prox;
    }
    return 0;
} 
*/


/* Cria um nova agendamento A contendo uma cópia exata doagendamento S.
   Retorna 1 se a operação foi bem sucedida e zero caso contrário 
int copia_agendamento(agendamento *S, agendamento *A){
    transacao * aux;

    aux = S->inicio;

    insere_fim_agendamento(aux->dado, m);
    while (aux->prox != NULL){        
        aux = aux->prox;
        insere_fim_agendamento(aux->dado, m);
    }  
    return 1;     
}
*/