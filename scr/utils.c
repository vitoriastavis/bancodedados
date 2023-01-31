#include <stdio.h>
#include <stdlib.h>
#include "../includes/utils.h"
#include "../includes/agenda.h"


void ler_transacoes()
{
    Transacao *tran = malloc(2 * sizeof(Transacao));
    int tempo, id;
    char op[3];
    char atributo[3];
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

        if(op[0] == 'C'){
            commits++;
        }else{
            tran[id_transacao].t_chegada = tempo;
            tran[id_transacao].id = id;
            tran[id_transacao].op = *op;
            tran[id_transacao].atributo = *atributo;

#ifdef DEBUG
    printf("%d %d %c %c\n", tran[id_transacao].t_chegada, tran[id_transacao].id, tran[id_transacao].op, tran[id_transacao].atributo);
#endif
            id_transacao++;
        }
    }
    // return tran;
}