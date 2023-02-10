#ifndef __UTILS_H__
#define __UTILS_H__

#include "transacao.h"
#include "grafo.h"
#include "agenda.h"

Escalonamento *cria_escalonamento();
void le_salva_entradas(Escalonamento *e);
void remove_ativas(int *ativas, int *tam, int id);
void adiciona_ativas(int *ativas, int *tam, int id);

// void adiciona_agenda(Agenda *agenda, Transacao *transacao);
// void le_salva_entrada(Agenda **agenda);
// void cria_escalonamento(Escalonamento *escalonamento);
// void imprime_resposta_final(Agenda a, int tem_ciclo, int equivalente);

#endif // __UTILS_H__