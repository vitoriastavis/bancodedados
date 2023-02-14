#include "utils.h"


int fatorial(int n);

int npr(int n);

int** cria_combinacoes(int n_trans, int n_visoes);

void cria_visao(Agenda *a, Agenda *visao, int **matriz, int cont_visoes, int n_trans);

void imprime(Agenda *a);

int adiciona_vetor(int vetor[], int pos, int valor);

int equivalente_por_visao(Agenda *a);