#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "graph.h"
#include "transaction.h"

#define MAX_LEN 4
#define MAX_T 10

void read_input(FILE *f)
{   
    transaction transacoes[MAX_T];
    int n_t = 0;

    char linha[MAX_LEN];
   /*int input;
    while ((input = getchar()) != EOF)
    {
        char line[MAX_LEN];
        transaction T;

        if (fscanf(f, "%s", line) != 1)
        {
            printf("nao sei \n");
            //return NULL;      
        }
        fscanf(f, "%*s");

        T.t_chegada = atoi(&line[0]);
        T.id = atoi(&line[1]);
        T.op = line[2];
        T.atributo = line[4]; 

        printf("%d %d %c %c \n", T.t_chegada, T.id, T.op, T.atributo);
        
        transacoes[n_t] = T;    
    }*/

    int i = 1;
    while(fgets(linha, MAX_LEN, f))
    {
        printf("Linha %d : %s\n", i, linha);
    
        i++; 
    }
}


int main(int argc, char ** argv)
{
    char *filename = argv[1];
    FILE *f;
    printf("%s \n", filename);
    f = fopen(filename, "w");
    if(!f)
        printf("deu cada \n");
    int n_transacoes;
    Graph grafo = graph_create(n_transacoes);

    read_input(f);
}