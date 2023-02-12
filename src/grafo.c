#include "../includes/grafo.h" 

Grafo *cria_grafo(int qtd_vertices)
{
    Grafo *g = malloc(sizeof(Grafo));
    g->n_vertice = qtd_vertices;
    g->n_arestas = 0;
    g->matriz_adj = (int **)malloc(qtd_vertices*sizeof(int *));
    for (int i = 0; i < qtd_vertices; i++)
        g->matriz_adj[i] = (int *)malloc(qtd_vertices*qtd_vertices*sizeof(int));
    memset(g->matriz_adj[0], 0, qtd_vertices*sizeof(int));

    return g;
}

void adiciona_aresta(Grafo *g, int ti, int tj)
{
    g->n_arestas += 1;
    g->matriz_adj[ti][tj] = 1;
}

int DFS(Grafo *g, int *visitados, int v){
    int tem_ciclo = 0;

    if (visitados[v]) 
        return 1;

    visitados[v] = 1;
    for (int i = 0; i < g->n_vertice; i++) {
        if(g->matriz_adj[v][i] == 1){
            tem_ciclo = DFS(g, visitados, i);
            if (tem_ciclo){
                visitados[v] = 0;
                return 1;
            }
        }
    }
    visitados[v] = 0;
    return 0;
}

/* Retorna 1 caso tenho e 0 caso não tenha */
int verifica_existencia_ciclo(Grafo *g)
{
    int *visitados = malloc(g->n_vertice*sizeof(int));
    memset(visitados, 0, g->n_vertice*sizeof(int));
    int tem_ciclo;

    for (int i = 0; i < g->n_vertice; i++) {
        visitados[i] = 1;
        for (int j = 0; j < g->n_vertice; j++){
            if (g->matriz_adj[i][j] == 1){
                tem_ciclo = DFS(g, visitados, j);
                if(tem_ciclo)
                {
                    free(visitados);
                    return 1;
                }
            }
        }
        visitados[i] = 0;
    }
    free(visitados);
    return 0;
}

/* --- Funcoes auxiliares --- */
void imprime_grafo(Grafo *g)
{
    int tam = g->n_vertice;
    printf("\n\n---Informacoes sobre grafo---\n");
    printf("N vertices: %d\nArestas: %d\nMatriz de Adjacencia:\n", tam, g->n_arestas);
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++){
            printf("%d ", g->matriz_adj[i][j]);
        }
        printf("\n");
    }
}