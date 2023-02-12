#ifndef __UTILS_H__
#define __UTILS_H__

#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>


/*!
    @brief Função que aloca memória para estrutura de escalonamento.
    @param None
    @return Ponteiro de acesso.
*/
Escalonamento *cria_escalonamento();

/*!
    @brief Função que lê dados de entrada e armazena na estrutura adequada.
    @param e: Ponteiro para acesso à estrutura de escalonamento
    @return None
*/
void le_salva_entradas(Escalonamento *e);

/*!
    @brief Função que remove um item de um vetor de inteiros.
    @param ativas: Ponteiro para acesso ao array que será feito a operação
    @param tam: Ponteiro para uma variável dinâmica que indica o tamanho do array
    @param id: Identificador do item a ser removido 
    @return None
*/
void remove_ativas(int *ativas, int *tam, int id);

/*!
    @brief Função que adiciona um item a um vetor de inteiros.
    @param ativas: Ponteiro para acesso ao array que será feito a operação
    @param tam: Ponteiro para uma variável dinâmica que indica o tamanho do array
    @param id: Identificador do item a ser inserido
    @return None
*/
void adiciona_ativas(int *ativas, int *tam, int id);

/*!
    @brief Função que imprime no arquivo de saida a resposta resultante de todo o algoritmo.
    @param a: Ponteiro para acesso à estrutura de agenda
    @param id_agenda: Identificador da agenda sendo processada
    @param tem_ciclo: Variável que representa um booleano e indica se há ciclo no grafo de conflito ou não
    @param equivalente: Variável que representa um booleano e indica se as visões são equivalentes ou não
    @return None
*/
void imprime_resposta_final(Agenda *a, int id_agenda, int tem_ciclo, int equivalente);

#endif // __UTILS_H__