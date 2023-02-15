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

/*!
    @brief Função que aloca memória para estrutura de grafos.
    @param qtd_vertices: Quantidade de vértices que terão o grafo
    @return Ponteiro de acesso.
*/
Grafo *cria_grafo(int qtd_vertices);

/*!
    @brief Função que adiciona uma aresta entre dois vértices do grafo.
    @param ti: Vértice de origem
    @param tj: Vértice de destino
    @return None
*/
void adiciona_aresta(Grafo *g, int ti, int tj);

/*!
    @brief Função auxiliar que imprime dados do grafo.
    @param g: Ponteiro de acesso ao grafo
    @return None
*/
void imprime_grafo(Grafo *g);

/*!
    @brief Função percorre matriz de adjacência e verifica se há ciclo.
    @param g: Ponteiro de acesso ao grafo
    @return Verdadeiro(1) ou Falso(0).
*/
int verifica_existencia_ciclo(Grafo *g);

/*!
    @brief Função que faz busca em profundidade verificando se arestas já foram percorridas mais de uma vez.
    @param g: Ponteiro de acesso ao grafo
    @param v: Vértice que será testado
    @return Verdadeiro(1) ou Falso(0).
*/
int DFS(Grafo *g, int *visitados, int v);

#endif // __GRAFO_H__