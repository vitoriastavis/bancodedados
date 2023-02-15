#ifndef __AGENDA_H__
#define __AGENDA_H__

#include "../includes/transacao.h"

/*!
    @brief Inicializa estrutura de agenda
    @param 
    @return Agenda inicializada
*/
Agenda *cria_agenda();

/*!
    @brief Adiciona uma transação no final de uma agenda, 
    @param t: Transacao a ser inserida
    @param a: Agenda para inserir
    @return Void
*/
void adiciona_info_agenda(Transacao *t, Agenda *a);

/*!
    @brief Constroi vetor com ids unicos da agenda 
    @param a: Agenda a ser percorrida
    @return Vetor com ids unicos
*/
int *salva_ids(Agenda *agenda);

/*!
    @brief Imprime ids unicos de uma agenda 
    @param a: Agenda para inserir
    @return Void
*/
void imprime_ids(Agenda *a);

/*!
    @brief Imprime todas as informacoes de um agendamento, separando pelas agendas
    @param e: Escalonamento a ser imprimido
    @return Void
*/
void imprime_agenda_completa(Escalonamento *e);

#endif // __AGENDA_H__