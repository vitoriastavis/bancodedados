#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"

#define MAX_TRANS 10
#define MAX_LENGTH 10

transacao* ler_transacoes(char *filename_in){
    agendamento S = malloc(MAX_TRANS*sizeof(agendamento));
    transacao *tran = malloc(sizeof(transacao));

    int tempo;
    int id;
    char op, atr;
    int commits = 0;
    int n_transacoes = 0;

    /*char linha[MAX_LENGTH] = {0};
    unsigned int n_linhas = 0;*/

    /*FILE *fp;      
    fp = fopen(filename_in, "r");  */

    if(fp == NULL){
        perror("Error in opening file");
        return NULL;
    }

    while (!feof(fp) || commits == n_transacoes){

        fscanf(stdin, "%d", &tempo);

        if (tempo == -1)
            break;

        fscanf(stdin, "%d", &id);
        fscanf(stdin, "%c", op);
        fscanf(stdin, "%c", atr);

        if(op == 'C')
            commits++;
        }else{
            tran->t_chegada = tempo;
            tran->id = id;
            tran->operacao = op;
            tran->atributo = atr;           
        }

        printf("%d %d %s %s\n", tempo, id, op, atr);

        if (id > n_transacoes)
            n_transacoes++;

        /*
        VERSAO C FGETS
        fgets(linha, MAX_LENGTH, fp);       
        //printf("linha[%02d]: %s", ++n_linhas, linha);   

        tempo = atoi(&linha[0]);
        id = atoi(&linha[2]);
        op = linha[4];
        atr = linha[6];

        //printf("%d %d %c %c \n", tempo, id, op, atr);

        if(op == 'C')
            commits++;
        
        tran->t_chegada = tempo;
        tran->id = id;
        tran->op = op;
        tran->atributo = atr;
        tran->

        agendamento[n_transacoes] = tran;

        if (id > n_transacoes)
            n_transacoes++;

        printf("%d %d %c %c \n", tran->t_chegada, tran->id, tran->op, tran->atributo);
        */
    
    
    /*
    while (!feof(fp))
    {
        fscanf(fp, "%d %d %c %c", tempo, id, op, atr);
        printf("%d %d %c %c \n", &tempo, id, &op, &atr);
        
        if(op == 'C'){
            commits++;
        }else{
            tran->t_chegada = tempo;
            tran->id = id;
            tran->op = op;
            tran->atributo = atr;

            n_transacoes++;
        }
        //printf("%d %d %s %s\n", tempo, id, &op, &atr);
    }
    */
    fclose(fp);
    return tran;

}

