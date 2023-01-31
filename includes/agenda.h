#ifndef AGENDA_H_
#define AGENDA_H_

typedef struct Transacao
{
    int t_chegada;
    int id;
    char op;
    char atributo;
} Transacao;

// Guarda se transacao foi commitada ou nao
typedef struct idTransacao {	
	int id;								
	short int foi_comitado;					
} idTransacao;

// Agenda com todas as transacoes
typedef struct Agenda
{
    int id;
    int tam;
    Transacao *idTransacao;
}Agenda;

#endif