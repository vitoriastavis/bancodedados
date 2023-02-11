#ifndef __AGENDA_H__
#define __AGENDA_H__

#include "../includes/transacao.h"

Agenda *cria_agenda();;
void adiciona_info_agenda(Transacao *t, Agenda *a);
int *salva_ids(Agenda *agenda);
void imprime_ids(Agenda *a);
void imprime_agenda_completa(Escalonamento *e);

#endif // __AGENDA_H__