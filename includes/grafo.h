#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Grafo
{
    int n_vertice;
    int n_arestas;
    int **matriz_adj;
} Grafo;

Grafo *cria_grafo(int qtd_vertices);
void adiciona_aresta(Grafo *g, int ti, int tj);
void imprime_grafo(Grafo *g);
int verifica_existencia_ciclo(Grafo *g);
int DFS(Grafo *g, int *visitados, int v);

#endif // __GRAFO_H__