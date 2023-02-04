#ifndef __TRANSACAO_H__
#define __TRANSACAO_H__

typedef struct Transacao Transacao;

struct Transacao {
    short int  tempo_chegada;
    int identificador;
    char operacao;
    char atributo;
    int num_adjacentes;
    Transacao **adjacencias;
    Transacao *proximo;
};

void adiciona_aresta(Transacao *transacoes, int ti, int tj);
void adiciona_dependencia_transacoes(Transacao *transacoes, int num_transacoes);
void imprime_transacao(Transacao *transacoes, int num_transacoes);

#endif // __TRANSACAO_H__