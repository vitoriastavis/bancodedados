#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "graph.h"
#include "transaction.h"

#define MAX_LEN 100

void read_input(FILE *f)
{
    char line[MAX_LEN];

    Transaction *transacao = malloc(sizeof(Transaction));

    if (fscanf(f, "%s", line) != 1)
    {
        free(transacao);
        return NULL;

        
    }

}


int main(int argc, char ** argv)
{
    int n_transacoes;
    Graph grafo = graph_create(n_transacoes);

}