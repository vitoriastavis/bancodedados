#include <stdio.h>
#include <stdlib.h>
#include "../includes/transaction.h"


void ler_transacoes()
{
    // transaction *tran = malloc(2 * sizeof(transaction));
    int tempo, id;
    char op[10];
    char atributo[10];
    int commits = 0;
    int id_transacao = 0;

    while (!feof(stdin))
    {
        fscanf(stdin, "%d", &tempo);

        if (tempo == -1)
            break;

        fscanf(stdin, "%d", &id);
        fscanf(stdin, "%s", op);
        fscanf(stdin, "%s", atributo);

        if(op == 'C'){
            commits++;
        }else{
            tran->t_chegada = tempo;
            tran->id = id;
            tran->op = op;
            tran->atributo = atributo;

            id_transaction++;
        }
        printf("%d %d %s %s\n", time, id, op, atributo);
    }
    // return tran;
}