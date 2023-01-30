#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/utils.h"

int main(int argc, char ** argv)
{
    char *filename_out = argv[2];
    FILE *file_out;
    transacao *t = NULL;

    file_out = fopen(filename_out, "w");

    if (!file_out)
    {
        fprintf(stderr, "Erro na abertura do arquivo de saída.");
        exit(0);
    }

    printf("vou dar read transacao %s \n", filename_out);
    t = read_transacoes(argv[1]);

    fclose(file_out);
    return 0;
}