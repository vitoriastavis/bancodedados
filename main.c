#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/utils.h"
#include "includes/transaction.h"

#define MAX_LEN 5
#define MAX_T 10

int main(int argc, char ** argv)
{
    char *filename_out = argv[1];
    FILE *file_out;
    transaction *t = NULL;

    file_out = fopen(filename_out, "w");

    if (!file_out)
    {
        fprintf(stderr, "Erro na abertura do arquivo de saída.");
        exit(0);
    }

    t = read_transactions();

    fclose(file_out);
    return 0;
}