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

typedef struct Agenda
{
    int id_esc;
    int num_transacoes;
    Transacao *lista_transacoes;
    Grafo grafo_gerado;
}Agenda;

typedef struct Escalonamento
{
    int total_agendas;
    Agenda *lista_escalonamento;
}Escalonamento;

void adiciona_dependencia_transacoes(Agenda *agenda);
void imprime_transacao(Transacao *transacoes, int num_transacoes);

#endif // __TRANSACAO_H__