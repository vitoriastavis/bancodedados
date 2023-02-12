#ifndef __AGENDA_H__
#define __AGENDA_H__

#include "transacao.h"

/*!
    @brief Função que aloca memória para estrutura de agenda.
    @param None
    @return Ponteiro de acesso.
*/
Agenda *cria_agenda();

/*!
    @brief Função que salva informações da transação na lista de transações da agenda.
    @param t: Ponteiro para acesso à estrutura da transação
    @param a: Ponteiro para acesso à estrutura de agenda
    @return None
*/
void adiciona_info_agenda(Transacao *t, Agenda *a);

/*!
    @brief Função que filtra identificadores únicos da lista de transações.
    @param a: Ponteiro para acesso à estrutura de agenda
    @return Array com identificadores únicos.
*/
int *salva_ids(Agenda *agenda);

/*!
    @brief Função auxiliar que imprime identificadores únicos da agenda.
    @param a: Ponteiro para acesso à estrutura de agenda
    @return None
*/
void imprime_ids(Agenda *a);

/*!
    @brief Função auxiliar que imprime dados de todas as agendas do escalonamento.
    @param e: Ponteiro para acesso à estrutura de escalonamento
    @return None
*/
void imprime_agenda_completa(Escalonamento *e);

#endif // __AGENDA_H__