#include <stdio.h>
#include <stdlib.h>
#include "../includes/utils.h"
#include "../includes/grafo.h"

#define MAX_TRANSACOES 100
#define MAX_LENGTH 2


/* Le e armazena dados lidos do input */
int le_salva_entrada(Transacao *transacoes, Grafo *g) {
    int num_transacoes = 0;
    int tempo, id;
    char op[MAX_LENGTH];
    char atr[MAX_LENGTH];
    int max = MAX_TRANSACOES;


    /* Guarda apenas os valores lidos */
    while (!feof(stdin)) {

        fscanf(stdin, "%d", &tempo);

        /* Para caso tenha linha em branco ou arquivo tenha terminado */
        if (tempo == -1)
            break;

        fscanf(stdin, "%d", &id);
        fscanf(stdin, "%s", op);
        fscanf(stdin, "%s", atr);

        transacoes[num_transacoes].tempo_chegada = tempo;
        transacoes[num_transacoes].identificador = id;
        transacoes[num_transacoes].operacao = op[0];
        transacoes[num_transacoes].atributo = atr[0];
        transacoes[num_transacoes].num_adjacentes = 0;
        transacoes[num_transacoes].transacoes_adjacentes = malloc(MAX_TRANSACOES * sizeof(int));
        transacoes[num_transacoes].proximo = malloc(MAX_TRANSACOES * sizeof(Transacao));
        
        num_transacoes++;

        adiciona_no(g, id);

        /* Aloca memória dinamicamente */
        if (num_transacoes == max) {
            max *= 2;
            transacoes = realloc(transacoes, max * sizeof(Transacao));
        }
    }
    return num_transacoes;
}