#ifndef __UTILS_H__
#define __UTILS_H__

#include "transacao.h"
#include "grafo.h"

void le_salva_entrada(Escalonamento *escalonamento);
void remove_ativas(int *ativas, int *tam, int id);
void adiciona_ativas(int *ativas, int *tam, int id);
void cria_escalonamento(Escalonamento *escalonamento);
void imprime_resposta_final(Agenda a, int tem_ciclo);

#endif // __UTILS_H__