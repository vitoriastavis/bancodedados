#include <stdio.h>
#include <stdlib.h>
#include "includes/utils.h"
#include "includes/transacao.h"

#define MAX_TRANSACOES 1000

int main(int argc, char ** argv)
{
    Transacao *transacoes = malloc(MAX_TRANSACOES * sizeof(Transacao));
    int num_transacoes = 0;
    
    num_transacoes = read_and_save_input(transacoes);
    adiciona_dependencia_transacoes(transacoes, num_transacoes);
    imprime_transacao(transacoes, num_transacoes);

    return 0;
}