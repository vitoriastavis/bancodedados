#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/utils.h"

#define MAX_TRANS 10

int main(int argc, char ** argv)
{
    char *arquivo = argv[1];
    FILE *arquivo_saida;
    agendamento *S = malloc(MAX_TRANS*sizeof(agendamento)); 
    cria_agendamento(S);

    arquivo_saida = fopen(arquivo, "w");

    // if (!arquivo_saida)
    // {
    //     fprintf(stderr, "Erro na abertura do arquivo de saída.");
    //     exit(0);
    // }
  
    ler_transacoes(S);
    // guarda_ordem_cronologica(S);

    // fclose(arquivo_saida);
    return 0;
}