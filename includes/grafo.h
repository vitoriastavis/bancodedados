#ifndef __GRAFO_H__
#define __GRAFO_H__

typedef struct Vertice
{
    int id;
    int qtd_vizinhos;
    int *lista_vizinhos;
}Vertice;

typedef struct Grafo
{
    int n_vertice;
    int n_arestas;
    Vertice *lista_vertices;
} Grafo;

void cria_grafo(Grafo *g);
void adiciona_no(Grafo *g, int id);
int existe_vertice(Grafo *g, int id);
void imprime_grafo(Grafo *g);
void adiciona_aresta(Grafo *g, int ti, int tj);
int encontra_posicao(Grafo *g, int ti);

#endif // __GRAFO_H__