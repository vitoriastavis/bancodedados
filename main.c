#include <stdio.h>
#include <stdlib.h>
#include "includes/utils.h"

int main(int argc, char ** argv)
{
    Escalonamento *escalonamento = (Escalonamento*)malloc(sizeof(Escalonamento));
    
    le_salva_entrada(escalonamento);

    int num_agendas = escalonamento->total_agendas;

    /* Percorre cada grupo de transacoes de cada agenda */
    for(int agenda = 0; agenda < num_agendas; agenda++) {
        adiciona_dependencia_transacoes(&(escalonamento->lista_escalonamento[agenda]));

        int tem_ciclo = verifica_existencia_ciclo(&(escalonamento->lista_escalonamento[agenda].grafo_gerado));

        imprime_resposta_final(escalonamento->lista_escalonamento[agenda], tem_ciclo);
    }

    return 0;
}