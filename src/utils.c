#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"

#define MAX_LENGTH 2

void ler_transacoes(agendamento *S){   
    cria_agendamento(S);

    int tempo, id;
    char op[MAX_LENGTH];
    char atr[MAX_LENGTH];
    int commits;
    int id_transacao;

    while (!feof(stdin))
    {
        transacao *tran = malloc(sizeof(transacao));

        fscanf(stdin, "%d", &tempo);

        if (tempo == -1)
            break;

        fscanf(stdin, "%d", &id);
        fscanf(stdin, "%s", op);
        fscanf(stdin, "%s", atr);
        
        tran->t_chegada = tempo;
        tran->id = id;
        tran->operacao = op[0];
        tran->atributo = atr[0];

        // imprime_transacao(tran);

        insere_agendamento(tran, S);
    }

    imprime_agendamento(S);
    guarda_indices_unicos(S);  
}

