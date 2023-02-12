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

/*!
    @brief Função que aloca memória para estrutura de transação.
    @param tempo: Timestamp da transação
    @param id: Identificador da transação
    @param op: Operação feita pela transação
    @param atr: Atributo utilizado pela transação
    @return Ponteiro de acesso.
*/
Transacao *cria_transacao(int tempo, int id, char op, char atr);

/*!
    @brief Função auxiliar que imprime dados da transação.
    @param a: Ponteiro para acesso à estrutura de agenda
    @return None
*/
void imprime_transacao(Agenda *a);

#endif // __TRANSACAO_H__