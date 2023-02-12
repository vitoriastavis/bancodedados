#ifndef __TRANSACAO_H__
#define __TRANSACAO_H__

#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Transacao Transacao;

struct Transacao {
    short int  tempo_chegada;
    int identificador;
    char operacao;
    char atributo;
    Transacao *anterior;
    Transacao *proximo;
};

typedef struct Agenda
{
    int tam;
    int num_transacoes;
    int *lista_ids_unicos;
    Transacao *inicio;
    Transacao *fim;
}Agenda;

typedef struct Escalonamento
{
    int total_agendas;
    Agenda **lista_escalonamento;
}Escalonamento;

Transacao *cria_transacao(int tempo, int id, char op, char atr);
void imprime_transacao(Agenda *a);

#endif // __TRANSACAO_H__