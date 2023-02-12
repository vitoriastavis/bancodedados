#ifndef __UTILS_H__
#define __UTILS_H__

#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>

Escalonamento *cria_escalonamento();
void le_salva_entradas(Escalonamento *e);
void remove_ativas(int *ativas, int *tam, int id);
void adiciona_ativas(int *ativas, int *tam, int id);
void imprime_resposta_final(Agenda *a, int id_agenda, int tem_ciclo, int equivalente);

#endif // __UTILS_H__