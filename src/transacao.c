#include <stdio.h>
#include <stdlib.h>
#include "../includes/transacao.h"

void adiciona_dependencia_transacoes(Agenda *agenda)
{
    int num_transacoes = agenda->num_transacoes;
    Transacao *aux = agenda->lista_transacoes;
    Grafo aux_grafo = agenda->grafo_gerado;

    /* Guarda dependencia por conflito */
    for (int i = 0; i < num_transacoes; i++) {
        char atributo = aux[i].atributo;
        char operacao = aux[i].operacao;
        int id = aux[i].identificador;

        /* Guarda dependencia por tempo */
        if (i + 1 < num_transacoes) {
            aux[i].proximo = &aux[i+1];  
        }

        for (int j = i + 1; j < num_transacoes; j++) {
                if (aux[j].atributo == atributo && aux[j].identificador != id) {
                    /* Regra 2 */
                    if (aux[j].operacao == 'R' && operacao == 'W') {
                        // printf("Regra 2. Ti: %d -> Tj: %d\n", aux[i].identificador, aux[j].identificador);
                        adiciona_aresta(&(aux_grafo), aux[i].identificador, aux[j].identificador);
                    } 
                    /* Regra 3 */
                    if (aux[j].operacao == 'W' && operacao == 'R') {
                        // printf("Regra 3. Ti: %d -> Tj: %d\n", aux[i].identificador, aux[j].identificador);
                        adiciona_aresta(&(aux_grafo), aux[i].identificador, aux[j].identificador);
                    } 
                    /* Regra 4 */
                    if (aux[j].operacao == 'W' && operacao == 'W') {
                        // printf("Regra 4. Ti: %d -> Tj: %d\n", aux[i].identificador, aux[j].identificador);
                        adiciona_aresta(&(aux_grafo), aux[i].identificador, aux[j].identificador);
                    }
                }
            }
    }

    agenda->grafo_gerado = aux_grafo;
}

/* --- Funcoes auxiliares --- */
void imprime_transacao(Transacao *transacoes, int num_transacoes)
{
    for (int i=0; i<num_transacoes; i++) {
        printf("%d %d %c %c\n", transacoes[i].tempo_chegada, transacoes[i].identificador, transacoes[i].operacao, transacoes[i].atributo);
    }
}