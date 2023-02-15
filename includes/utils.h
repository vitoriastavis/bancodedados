#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

/*!
    @brief Inicializa estrutura do Escalonamento
    @param 
    @return Uma estrutura do tipo Escalonamento inicializada
*/
Escalonamento *cria_escalonamento();

/*!
    @brief Le e armazena dados lidos do input nas estruturas de escalonamento e agenda
    @param e: Ponteiro para estrutura tipo Escalonamento
    @return void
*/
void le_salva_entradas(Escalonamento *e);

void remove_ativas(int *ativas, int *tam, int id);
void adiciona_ativas(int *ativas, int *tam, int id);

/*!
    @brief Imprime a saida final do programa
    @param a: Ponteiro para estrutura de agenda
    @param id_agenda: Identificador daquela agenda na lista de agendas do escalonamento
    @param serializavel: (1) passou no teste de seriabilidade por conflito, (0) se nao
    @param equivalente: (1) passou no teste de equivalencia por visao, (0) se nao
    @return void
*/
void imprime_resposta_final(Agenda *a, int id_agenda, int serializavel, int equivalente);

#endif // __UTILS_H__