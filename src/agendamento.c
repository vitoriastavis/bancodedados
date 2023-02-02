#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../includes/agendamento.h"

#define MAX_TRANS 10

/* Guarda uma transacao na lista de transacoes */
int guarda_transacao(transacao *t, agendamento *S, int pos){
    S->lista_transacoes[pos] = (transacao *)malloc(sizeof(transacao));

    S->lista_transacoes[pos]->t_chegada = t->t_chegada;
    S->lista_transacoes[pos]->id = t->id;
    S->lista_transacoes[pos]->operacao = t->operacao;
    S->lista_transacoes[pos]->atributo = t->atributo;
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
    S->qtd_transacoes = 0;
    S->lista_transacoes = (transacao **)malloc(MAX_TRANS*sizeof(transacao *));
    S->lista_escalonamentos = malloc(MAX_TRANS*sizeof(int));

    return 1;
}

/* Retorna 1 se a agendamento está vazio e zero caso contrário; */
int agendamento_vazio(agendamento *S){
    if (S->qtd_transacoes == 0)
        return 1;
    return 0;
}

// /* Remove todos os elementos doagendamento e aponta ela para NULL */
// void destroi_agendamento(agendamento *S){
//     transacao *aux;
 
//     if(agendamento_vazio(S)){
//         printf("não destruida: agendamento vazio\n");
//     }

//     while (S->inicio != NULL){
//         aux = S->inicio;
//         S->inicio = aux->prox;
//         S->tamanho--;
//         free(aux);
//     }        
// }

/* Insere a transacao no fim do agendamento;
   Retorna 1 se a operação foi bem sucedida e zero caso contrario */
int insere_agendamento(transacao *t_nova, agendamento *S){ 

    if(!S || !t_nova)
        return 0;

    if(agendamento_vazio(S)){
        guarda_transacao(t_nova, S, 1);
    }
    else {
        guarda_transacao(t_nova, S, S->qtd_transacoes+1);
    } 
    S->qtd_transacoes++; 
    return 1;    
}

/* Imprime os elementos doagendamento, do inı́cio ao final.
   Se ela for vazio não imprime nada*/
void imprime_agendamento(agendamento *S){
    transacao *posicao;   

    if (agendamento_vazio(S)){ 
        return;
    }

    int tam = S->qtd_transacoes;
    printf("tam: %d \n", S->qtd_transacoes);  

    for (int i = 1; i <= tam; i++){
        imprime_transacao(S->lista_transacoes[i]); 
    }
    printf("\n");
}

void guarda_indices_unicos(agendamento *S){
    int qtd_transacoes = S->qtd_transacoes;
    int id;

    for (int i = 0; i < qtd_transacoes; i++){
        id = S->lista_transacoes[i]->id;

        if (!verifica_existencia_id(id, S)){
            S->lista_escalonamentos[id].idEsc = id;
        }

        S->lista_escalonamentos[id].tam_transacao++;

        if (S->lista_transacoes[i]->operacao == 'C'){
            S->lista_escalonamentos[id].commitado = 1;
        }
    } 
}

int verifica_existencia_id(int id, agendamento *S){
    short int existe = 0;

    for (int i = 0; i < VERIFICAR_COMO; i++) {
        if (id == S->lista_escalonamentos[id].idEsc) {
            existe = 1;
            break;
        }
    }
    return existe;
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