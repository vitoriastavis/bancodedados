#include <stdio.h>
#include <stdlib.h>
#include "includes/utils.h"
#include "includes/visao.h"

int main(int argc, char ** argv)
{
    Escalonamento *escalonamento = cria_escalonamento();

    le_salva_entradas(escalonamento);

    /* Percorre cada grupo de transacoes de cada agenda */
    for(int agenda = 0; agenda < escalonamento->total_agendas; agenda++) {
        //serializavel = eh_serializavel(escalonamento->lista_escalonamento[agenda]);

        equivalente_por_visao(escalonamento->lista_escalonamento[agenda]);

        //imprime_resposta_final(escalonamento->lista_escalonamento[agenda], agenda, serializavel, 0);
    }

    return 0;
}