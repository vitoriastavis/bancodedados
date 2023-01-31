#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/utils.h"

int main(int argc, char ** argv)
{
    char *arquivo = argv[1];
    FILE *arquivo_saida;
    // transaction *t = NULL;

    arquivo_saida = fopen(arquivo, "w");

    // if (!arquivo_saida)
    // {
    //     fprintf(stderr, "Erro na abertura do arquivo de saída.");
    //     exit(0);
    // }

    ler_transacoes();

    // fclose(arquivo_saida);
    return 0;
}