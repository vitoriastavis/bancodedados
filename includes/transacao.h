#ifndef __TRANSACAO_H__
#define __TRANSACAO_H__

#include "grafo.h"

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
    @brief Inicializa estrutura de transacao
    @param 
    @return Transacao inicializada
*/
Transacao *cria_transacao(int tempo, int id, char op, char atr);

/*!
    @brief Imprime transacoes de uma agenda
    @param a: Agenda a ser impressa
    @return Void
*/
void imprime_transacao(Agenda *a);

#endif // __TRANSACAO_H__