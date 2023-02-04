#ifndef __TRANSACAO_H__
#define __TRANSACAO_H__

#include "grafo.h"

typedef struct Transacao Transacao;

struct Transacao {
    short int  tempo_chegada;
    int identificador;
    char operacao;
    char atributo;
    int num_adjacentes;
    int *transacoes_adjacentes;
    Transacao *proximo;
};

void adiciona_dependencia_transacoes(Transacao *transacoes, int num_transacoes, Grafo *g);
void imprime_transacao(Transacao *transacoes, int num_transacoes);

#endif // __TRANSACAO_H__