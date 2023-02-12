#include "../includes/serializavelConflito.h"

int eh_serializavel(Agenda *a)
{
    Grafo *grafo = cria_grafo(a->num_transacoes);
    Transacao *tran = a->inicio;
    Transacao *prox;
    int serializavel;
    int pos_ini = a->lista_ids_unicos[0];

    for(int i = 0; i < a->tam - 1; i++)
    {
        prox = tran->proximo;

        for(int j = i + 1; j < a->tam; j++)
        {
            /* Verifica se não sao da mesma transacao e se usam o mesmo atributo */
            if(prox->identificador != tran->identificador && prox->atributo == tran->atributo){

                /* Regra 2 */
                if(prox->operacao == 'R' && tran->operacao == 'W')
                    adiciona_aresta(grafo, tran->identificador - pos_ini, prox->identificador - pos_ini);

                /* Regra 3 */
                if(prox->operacao == 'W' && tran->operacao == 'R')
                    adiciona_aresta(grafo, tran->identificador - pos_ini, prox->identificador - pos_ini);

                /* Regra 4 */
                if(prox->operacao == 'W' && tran->operacao == 'W')
                    adiciona_aresta(grafo, tran->identificador - pos_ini, prox->identificador - pos_ini);
            }
            prox = prox->proximo;
        }
        tran = tran->proximo;
    }

    serializavel = verifica_existencia_ciclo(grafo);

    free(tran);
    free(prox);
    free(grafo);

    return serializavel;
} 