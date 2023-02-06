#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/grafo.h" 

void adiciona_no(Grafo *g, int id)
{
    if (!existe_vertice(g, id)) {
        int tam = g->n_vertice;
        g->lista_vertices[tam].id = id;
        g->lista_vertices[tam].qtd_vizinhos = 0;
        g->lista_vertices[tam].lista_vizinhos = (int*)malloc(sizeof(int) * (tam+1));
        g->n_vertice += 1;
    }
}

int existe_vertice(Grafo *g, int id)
{
    int tam = g->n_vertice;

    for (int i = 0; i < tam; i++) {
        if (g->lista_vertices[i].id == id) {
            return 1;
        }
    }
    // significa que o vértice não existia, pode adicionar
    return 0;
}

void adiciona_aresta(Grafo *g, int ti, int tj)
{
    g->n_arestas += 1;
    int pos_ti = encontra_posicao(g, ti);
    int tam = g->lista_vertices[pos_ti].qtd_vizinhos;

    g->lista_vertices[pos_ti].lista_vizinhos[tam] = tj;
    g->lista_vertices[pos_ti].qtd_vizinhos += 1;
}

int encontra_posicao(Grafo *g, int ti)
{
    for (int i = 0; i < g->n_vertice; i++) {
        if (g->lista_vertices[i].id == ti) {
            return i;
        }
    }
    return -1;
}


/* --- TESTE DE SERIALIDADE --- */

void inicializa_matriz(Grafo *g) {
    /* Aloca memoria */
    g->matriz_adj = (int**)malloc(g->n_vertice*sizeof(int*));
    for(int m = 0; m < g->n_vertice; m++) {
        g->matriz_adj[m] = (int*)malloc(g->n_vertice*sizeof(int));
    }

    memset(*(g->matriz_adj), 0, g->n_vertice*2*sizeof(int));
}

void adiciona_dependencia(Grafo *g, int ti, int tj)
{
    g->matriz_adj[ti][tj] = 1;
}

void cria_matriz_adjacencia(Grafo *g) {
    inicializa_matriz(g);
    for (int i = 0; i < g->n_vertice; i++) {
        Vertice vertice = g->lista_vertices[i];
        int v1 = vertice.id;

        for (int j = 0; j < vertice.qtd_vizinhos; j++) {
            int v2 = vertice.lista_vizinhos[j];
            adiciona_dependencia(g, encontra_posicao(g, v1), encontra_posicao(g, v2));
        }
    }
}

void DFS(Grafo *g, int *visitados, int v, int *tem_ciclo){
    visitados[v] = 1;

    for (int i = 0; i < g->n_vertice; i++) {
        if(g->matriz_adj[v][i] == 1 && visitados[i] == 0){
            DFS(g, visitados, i, tem_ciclo);
        } 
        else if (g->matriz_adj[v][i] == 1 && visitados[i]){
            *tem_ciclo = 1;
        }
    }
}

int verifica_existencia_ciclo(Grafo *g)
{
    cria_matriz_adjacencia(g);

    int visitados[g->n_vertice];
    memset(visitados, 0, sizeof(visitados));

    int tem_ciclo = 0;

    for (int i = 0; i < g->n_vertice; i++) {
        if (!visitados[i]) {
            DFS(g, visitados, i, &tem_ciclo);
        }
    }
    return tem_ciclo;
}

/* --- Funcoes auxiliares --- */
void imprime_grafo(Grafo *g)
{
    int tam = g->n_vertice;
    printf("N vertices: %d, Arestas: %d\n", tam, g->n_arestas);
    for (int i = 0; i < tam; i++) {
        printf("Id: %d, n_vizinhos: %d, Vizinhos: \n", g->lista_vertices[i].id, g->lista_vertices[i].qtd_vizinhos);
        imprime_lista_vizinhos(g->lista_vertices[i]);
    }
}

void imprime_lista_vizinhos(Vertice v)
{
    int tam = v.qtd_vizinhos;
    for (int i = 0; i < tam; i++) {
        printf("%d ", v.lista_vizinhos[i]);
    }
    printf("\n");
}

void imprime_matriz(Grafo *g) {
    printf("Matriz de adjacência:\n");
    for (int i = 0; i < g->n_vertice; i++) {
        for (int j = 0; j < g->n_vertice; j++) {
            printf("%d ", g->matriz_adj[i][j]);
        }
        printf("\n");
    }
}