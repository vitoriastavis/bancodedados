#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"

#define MAX_TRANS 10
#define MAX_LENGTH 2

void ler_transacoes(){
    agendamento *S = malloc(MAX_TRANS*sizeof(agendamento));    
    cria_agendamento(S);

    int tempo, id;
    char op[MAX_LENGTH];
    char atr[MAX_LENGTH];
    int commits;
    int id_transacao;

    while (!feof(stdin))
    {
        transacao *tran = malloc(sizeof(transacao));
        cria_transacao(tran);

        fscanf(stdin, "%d", &tempo);

        if (tempo == -1)
            break;

        fscanf(stdin, "%d", &id);
        fscanf(stdin, "%s", op);
        fscanf(stdin, "%s", atr);

        if(op[0] == 'C')           
            commits++;
        
        tran->t_chegada = tempo;
        tran->id = id;
        tran->operacao = op[0];
        tran->atributo = atr[0];

        id_transacao++;
                
        //imprime_transacao(tran);

        insere_agendamento(tran, S);
    }

    imprime_agendamento(S);  
}