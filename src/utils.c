#include <stdio.h>
#include <stdlib.h>
#include "../includes/utils.h"
#include "../includes/grafo.h"

#define MAX_TRANSACOES 10
#define MAX_LENGTH 2

void cria_escalonamento(Escalonamento *escalonamento) 
{
    escalonamento->total_agendas = 0;
    escalonamento->lista_escalonamento = (Agenda*)malloc(MAX_TRANSACOES * sizeof(Agenda));

    for (int i = 0; i < MAX_TRANSACOES; i++) {
        escalonamento->lista_escalonamento[i].id_esc = i;
        escalonamento->lista_escalonamento[i].num_transacoes = 0;
        escalonamento->lista_escalonamento[i].lista_transacoes = (Transacao*)malloc(MAX_TRANSACOES * sizeof(Transacao));
        escalonamento->lista_escalonamento[i].grafo_gerado.n_vertice = 0;
        escalonamento->lista_escalonamento[i].grafo_gerado.n_arestas = 0;
        escalonamento->lista_escalonamento[i].grafo_gerado.lista_vertices = (Vertice*)malloc(MAX_TRANSACOES * sizeof(Vertice));
    }
}

/* Le e armazena dados lidos do input */
void le_salva_entrada(Escalonamento *escalonamento) 
{
    int num_transacoes = 0;
    int tempo, id;
    char op[MAX_LENGTH];
    char atr[MAX_LENGTH];

    /* Auxiliares */
    int ativas[MAX_TRANSACOES];
    int tam_ativas = 0;

    /* Cria escalonamento */
    cria_escalonamento(escalonamento);

    Agenda aux = escalonamento->lista_escalonamento[escalonamento->total_agendas];
    /* Guarda apenas os valores lidos */
    while (!feof(stdin)) {

        fscanf(stdin, "%d", &tempo);

        /* Para caso tenha linha em branco ou arquivo tenha terminado */
        if (tempo == -1)
            break;

        fscanf(stdin, "%d", &id);
        fscanf(stdin, "%s", op);
        fscanf(stdin, "%s", atr);

        if(op[0] == 'C') {
            remove_ativas(ativas, &tam_ativas, id);
        }
        else{
            adiciona_ativas(ativas, &tam_ativas, id);
        }

        /* Armazena dados das transacoes */
        aux.lista_transacoes[num_transacoes].tempo_chegada = tempo;
        aux.lista_transacoes[num_transacoes].tempo_chegada = tempo;
        aux.lista_transacoes[num_transacoes].identificador = id;
        aux.lista_transacoes[num_transacoes].operacao = op[0];
        aux.lista_transacoes[num_transacoes].atributo = atr[0];
        aux.lista_transacoes[num_transacoes].num_adjacentes = 0;
        aux.lista_transacoes[num_transacoes].transacoes_adjacentes = malloc(MAX_TRANSACOES * sizeof(int));
        aux.lista_transacoes[num_transacoes].proximo = malloc(MAX_TRANSACOES * sizeof(Transacao));
        num_transacoes++;

        adiciona_no(&(aux.grafo_gerado), id);

        if (tam_ativas == 0) {
            aux.id_esc = escalonamento->total_agendas;
            aux.num_transacoes = num_transacoes;

            /* Atualiza variavel original */
            escalonamento->lista_escalonamento[escalonamento->total_agendas] = aux;
            escalonamento->total_agendas += 1;

            /* Atualiza variaveis para proxima agenda */
            aux = escalonamento->lista_escalonamento[escalonamento->total_agendas];
            num_transacoes = 0;
        }
    }
}

/* ----------------------------------- */

void remove_ativas(int *ativas, int *tam, int id)
{
    int tamanho = *tam;
    for (int i = 0; i < tamanho; i ++) {
        if (ativas[i] == id) {
            *tam = tamanho - 1;
            for(int j = i; j < tamanho; j++) {
                ativas[j] = ativas[j + 1];
            }
            break;
        }
    }
}

void adiciona_ativas(int *ativas, int *tam, int id)
{
    int tamanho = *tam;
    for (int i = 0; i < tamanho; i++) {
        if (ativas[i] == id) {
            return;
        }
    }
    ativas[tamanho] = id;
    *tam += 1;
}

void imprime_resposta_final(Agenda a, int tem_ciclo, int equivalente)
{
    /* Imprime identificado do escalonamento */
    printf("%d ", a.id_esc + 1);

    /* Imprime lista de transacoes */
    for(int i = 0; i < a.grafo_gerado.n_vertice; i++) {
        printf("%d", a.grafo_gerado.lista_vertices[i].id);
        if(i + 1 != a.grafo_gerado.n_vertice) {
            printf(",");
        }
    }

    /* Imprime resultado do algoritmo de garantia de serialidade */
    tem_ciclo ? printf(" NS "): printf(" SS ");

    equivalente ? printf("SV") : printf("NV");
    /* Imprime resultado do algoritmo de teste de equivalencia de visao */
    printf("\n");
}