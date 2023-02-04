#include <stdio.h>
#include <stdlib.h>
#include "../includes/grafo.h" 

#define MAX_TRANSACOES 100

void cria_grafo(Grafo *g)
{
    g->n_vertice = 0;
    g->n_arestas = 0;
    g->lista_vertices = (Vertice *)malloc(sizeof(Vertice));
}

void adiciona_no(Grafo *g, int id)
{
    if (!existe_vertice(g, id))
    {
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

    for (int i = 0; i < tam; i++)
    {
        if (g->lista_vertices[i].id == id)
        {
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
    for (int i = 0; i < g->n_vertice; i++)
    {
        if (g->lista_vertices[i].id == ti)
        {
            return i;
        }
    }
    return -1;
}

int tem_ciclo(Grafo *g)
{
    return 0; //False
}

/* --- Funcoes auxiliares --- */
void imprime_grafo(Grafo *g)
{
    int tam = g->n_vertice;
    printf("N vertices: %d, Arestas: %d\n", tam, g->n_arestas);
    for (int i = 0; i < tam; i++)
    {
        printf("Id: %d, n_vizinhos: %d\n", g->lista_vertices[i].id, g->lista_vertices[i].qtd_vizinhos);
    }
}