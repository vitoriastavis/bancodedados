#include <stdio.h>
#include <stdlib.h>
#include "../includes/transacao.h"

void adiciona_dependencia_transacoes(Transacao *transacoes, int num_transacoes, Grafo *g)
{
    /* Guarda dependencia por conflito */
    for (int i = 0; i < num_transacoes; i++)
    {
        char atributo = transacoes[i].atributo;
        char operacao = transacoes[i].operacao;
        int id = transacoes[i].identificador;

        /* Guarda dependencia por tempo */
        if (i + 1 < num_transacoes){
            transacoes[i].proximo = &transacoes[i+1];  
        }

        for (int j = i + 1; j < num_transacoes; j++) {
                if (transacoes[j].atributo == atributo && transacoes[j].identificador != id) {
                    /* Regra 2 */
                    if (transacoes[j].operacao == 'R' && operacao == 'W') {
                        printf("Regra 2. Ti: %d -> Tj: %d\n", transacoes[i].identificador, transacoes[j].identificador);
                        adiciona_aresta(g, transacoes[i].identificador, transacoes[j].identificador);
                    } 
                    /* Regra 3 */
                    if (transacoes[j].operacao == 'W' && operacao == 'R') {
                        printf("Regra 3. Ti: %d -> Tj: %d\n", transacoes[i].identificador, transacoes[j].identificador);
                        adiciona_aresta(g, transacoes[i].identificador, transacoes[j].identificador);
                    } 
                    /* Regra 4 */
                    if (transacoes[j].operacao == 'W' && operacao == 'W') {
                        printf("Regra 4. Ti: %d -> Tj: %d\n", transacoes[i].identificador, transacoes[j].identificador);
                        adiciona_aresta(g, transacoes[i].identificador, transacoes[j].identificador);
                    }
                }
            }
    }
}


/* --- Funcoes auxiliares --- */
void imprime_transacao(Transacao *transacoes, int num_transacoes)
{
    for (int i=0; i<num_transacoes; i++){
        printf("%d %d %c %c\n", transacoes[i].tempo_chegada, transacoes[i].identificador, transacoes[i].operacao, transacoes[i].atributo);
    }
}