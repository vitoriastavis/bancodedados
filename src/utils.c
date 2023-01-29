#include <stdio.h>
#include <stdlib.h>
#include "../includes/transaction.h"

#define N_TRANS_MAX 10

transaction* read_transactions()
{
    transaction *tran = malloc(2 * sizeof(transaction));
    int time, id;
    char op, attribute;
    int commits = 0;
    int id_transaction = 0;

    while (!feof(stdin))
    {
        fscanf(stdin, "%d %d %c %c", &time, &id, &op, &attribute);

        if(op == 'C'){
            commits++;
        }else{
            tran->t_chegada = time;
            tran->id = id;
            tran->op = op;
            tran->atributo = attribute;

            id_transaction++;
        }
        printf("%d %d %s %s\n", time, id, &op, &attribute);
    }
    return tran;
}

