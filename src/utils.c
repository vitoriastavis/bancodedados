#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"

#define MAX_TRANS 10
#define MAX_LENGTH 10

void ler_transacoes()
{
    transacao *tran = malloc(2 * sizeof(transacao));
    int tempo, id;
    char op[10];
    char atributo[10];
    int commits = 0;
    int id_transacao = 0;

    #ifdef DEBUG
        printf("Vou ler a entrada padrao\n");
    #endif

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

            id_transacao++;
        }
        printf("%d %d %s %s\n", tempo, id, op, atributo);
    }
    return tran;
}