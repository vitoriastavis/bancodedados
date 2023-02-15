#include "utils.h"

/*!
    @brief Imprime uma matriz
    @param matriz: Ponteiro duplo para estrutura da matriz
    @param lin: Numero de linhas da matriz
    @param col: Numero de colunas da matriz
    @return Void
*/
void imprime_matriz(int **matriz, int lin, int col);

/*!
    @brief Calcula o fatorial de um valor dado
    @param n: Valor cujo fatorial sera calculado
    @return Fatorial do valor
*/
int fatorial(int n);

/*!
    @brief Calcula numero de permutacoes/visoes pela formula de permutacao
    @param n: Valor para calculo de permutacoes, numero de transacoes
    @return Total de permutacoes/visoes
*/
int npr(int n);

/*!
    @brief Adiciona combinacoes na matriz de combinacoes, de acordo com as permutacoes do numero de transacoes
    @param n: Numero de transacoes
    @param matriz: Matriz para adicionar combinacoes nas colunas
    @return void
*/
void permuta(int n, int **matriz);

/*!
    @brief Aloca a matriz e chama a funcao permuta para preencher a matriz
    @param n_trans: Numero de transacoes
    @param n_visoes: Total de visoes, dado pela funcao npr
    @return Matriz de combinacoes
*/
int** cria_combinacoes(int n_trans, int n_visoes);

/*!
    @brief Adiciona transacoes à visao de acordo com sua combinacao na matriz
    @param a: Agenda original
    @param visao: Visao a ser preenchida
    @param matriz: Matriz de combinacoes
    @param cont_visoes: 
    @return Matriz de combinacoes
*/
void cria_visao(Agenda *a, Agenda *visao, int **matriz, int cont_visoes, int n_trans);

/*!
    @brief Adiciona um valor num vetor, apenas se este nao existe no vetor
    @param vetor: Vetor no qual o valor sera inserido
    @param pos: Posicao na qual inserir
    @param valor: Valor a ser inserido 
    @return Tamanho novo do vetor
*/
int add_vetor_unico(int vetor[], int pos, int valor);

/*!
    @brief Cria vetor unico dos atributos das operacoes da agenda, sem repeti-los
    @param a: Ponteiro para a agenda
    @param vetor: Vetor a ser preenchido
    @return Tamanho do vetor
*/
int vetor_unico_attrs(Agenda *a, int *vetor);

/*!
    @brief Retorna a posicao de um atributo no vetor unico de atributos
    @param vetor: Vetor unico de atributos
    @param atributo: Valor em ASCII do atributo da operacao
    @param tam_vetor: Tamanho do vetor
    @return Posicao no vetor ou -1 se nao existe
*/
int indice_vetor_unico(int *vetor, int atributo, int tam_vetor);

/*!
    @brief Verifica se dois vetores sao iguais
    @param v_a: Vetor da agenda a
    @param v_v: Vetor da visao v
    @param tam: tamanho do vetor
    @return (1) se sao iguais, (0) se nao
*/
int compara_vetores(int v_a[], int v_v[], int tam);

/*!
    @brief Faz o primeiro teste do algoritmo, se para cada leitura em Ti que teve antes uma escrita do mesmo atributo em Tj,
            a mesma ordem deve se repetir na visao
    @param n_trans: Numero de transacoes
    @param tam_agenda: Tamanho total da agenda
    @param leituras_a: Matriz de leituras feitas pela transacao por timestamp
    @param escritas_a: Matriz de escritas feitas pela transacao por timestamp
    @param cont_leitura_a: Vetor com numero de leituras de cada transacao
    @param leituras_v: Matriz de leituras feitas pela visao por timestamp
    @param escritas_v: Matriz de escritas feitas pela transacao por timestamp
    @return (1) se sao equivalentes, (0) se nao
*/
int teste_1(int n_trans, int tam_agenda, int** leituras_a, int** escritas_a, int* cont_leitura_a, int** leituras_v, int** escritas_v);

/*!
    @brief Faz o segundo teste do algoritmo, se na agenda original uma transacao faz a ultima leitura de um atributo,
            essa mesma transacao deve fazer a ultima leitura do atributo na visao
    @param tam_vetor: Tamanho do vetor de atributos especificos
    @param tam_agenda: Tamanho total da agenda
    @param n_trans: Numero de transacoes
    @param leituras_a: Matriz de leituras feitas pela transacao por timestamp
    @param escritas_v: Matriz de escritas feitas pela transacao por timestamp
    @param atributos_unicos: Vetor de atributos unicos das operacoes da agenda
    @return (1) se sao equivalentes, (0) se nao
*/
int teste_2(int tam_vetor, int tam_agenda, int n_trans, int** escritas_a, int** escritas_v, int* atributos_unicos);

/*!
    @brief Inicializa matrizes e vetores auxiliares, contabiliza as operacoes
    @param a: Agenda original
    @param visao: Visao a ser analisada
    @return Se a agenda como um todo eh equivalente por visao a alguma visao
*/
int analisa_visao(Agenda *a, Agenda *visao);

/*!
    @brief Cria combinacoes, visoes e testa elas
    @param a: Agenda original
    @return Se a agenda como um todo eh equivalente por visao a alguma visao
*/
int eh_equivalente(Agenda *a);