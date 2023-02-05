#ifndef __GRAFO_H__
#define __GRAFO_H__

typedef struct Vertice Vertice;

struct Vertice
{
    int id;
    int qtd_vizinhos;
    int *lista_vizinhos;
};

typedef struct Grafo
{
    int n_vertice;
    int n_arestas;
    Vertice *lista_vertices;
    int **matriz_adj;
} Grafo;

void cria_grafo(Grafo *g);
void adiciona_no(Grafo *g, int id);
int existe_vertice(Grafo *g, int id);
void imprime_grafo(Grafo *g);
void adiciona_aresta(Grafo *g, int ti, int tj);
int encontra_posicao(Grafo *g, int ti);
int verifica_existencia_ciclo(Grafo *g);
void DFS(Grafo *g, int *visitados, int v, int *tem_ciclo);
void imprime_matriz(Grafo *g) ;
void cria_matriz_adjacencia(Grafo *g);
void inicializa_matriz(Grafo *g);
void imprime_lista_vizinhos(Vertice v);

#endif // __GRAFO_H__