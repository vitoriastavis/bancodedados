#include <stdio.h>
#include <stdlib.h>
#include "../includes/agenda.h"

Agenda *cria_agenda()
{
    Agenda *a = malloc(sizeof(Agenda));
    a->num_transacoes = 0;
    a->inicio = NULL;
    a->fim = NULL;
    a->lista_ids_unicos = NULL;
    return a;
}

void adiciona_info_agenda(Transacao *t, Agenda *a)
{
    if(a->inicio == NULL && a->fim == NULL){
        a->inicio = t;
        a->fim = t;
        a->num_transacoes++;
        return;
    }
    else{
        a->fim->proximo = t;
        t->anterior = a->fim;
        a->fim = t;
        a->num_transacoes++;
    }
}