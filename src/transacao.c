#include "../includes/transacao.h"

Transacao *cria_transacao(int tempo, int id, char op, char atr)
{
    Transacao *t = malloc(sizeof(Transacao));
    t->tempo_chegada = tempo;
    t->identificador = id;
    t->operacao = op;
    t->atributo = atr;
    t->anterior = NULL;
    t->proximo = NULL;
    return t;
}

/* --- Funcoes auxiliares --- */
void imprime_transacao(Agenda *a)
{
    Transacao *t = a->inicio;
    for (int i=0; i<a->tam; i++) {
        printf("Tempo: %d\nId: %d\nOp:%c\nAtributo:%c\n\n", t->tempo_chegada, t->identificador, t->operacao, t->atributo);
        t = t->proximo;
    }
}