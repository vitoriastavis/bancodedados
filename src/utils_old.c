#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"

#define MAX_TRANS 10
#define MAX_LENGTH 10

transacao* read_transacoes(char *filename_in)
{
    schedule S = malloc(sizeof(schedule));
    transacao *tran = malloc(MAX_TRANS*sizeof(transacao));

    int time;
    int id;
    char op, attribute;
    int commits = 0;
    int n_transacoes = 0;

    char line[MAX_LENGTH] = {0};
    unsigned int line_count = 0;

    FILE *fp;      
    fp = fopen(filename_in, "r");  

    printf("vou entrar no while \n");

    if(fp == NULL) {
        perror("Error in opening file");
        return NULL;
    }

    while (!feof(fp) || commits == n_transacoes)
    {
        fgets(line, MAX_LENGTH, fp);       
        //printf("line[%02d]: %s", ++line_count, line);   

        time = atoi(&line[0]);
        id = atoi(&line[2]);
        op = line[4];
        attribute = line[6];

        //printf("%d %d %c %c \n", time, id, op, attribute);

        if(op == 'C')
            commits++;
        
        tran->t_chegada = time;
        tran->id = id;
        tran->op = op;
        tran->atributo = attribute;
        tran->

        schedule[n_transacoes] = tran;

        if (id > n_transacoes)
            n_transacoes++;

        printf("%d %d %c %c \n", tran->t_chegada, tran->id, tran->op, tran->atributo);
    }
    /*
    while (!feof(fp))
    {
        fscanf(fp, "%d %d %c %c", time, id, op, attribute);
        printf("%d %d %c %c \n", &time, id, &op, &attribute);
        
        if(op == 'C'){
            commits++;
        }else{
            tran->t_chegada = time;
            tran->id = id;
            tran->op = op;
            tran->atributo = attribute;

            n_transacoes++;
        }
        //printf("%d %d %s %s\n", time, id, &op, &attribute);
    }
    */
    fclose(fp);
    return tran;

}

