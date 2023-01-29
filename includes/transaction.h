typedef struct transaction
{
    int t_chegada;
    int id;
    char op;
    char atributo;
} transaction;

// Guarda se transacao foi commitada ou nao
typedef struct idTransaction {	
	int id;								
	short int isCommited;					
} idTransaction;

// Agenda com todas as transacoes
typedef struct scheduling
{
    int id;
    int size;
    transaction *idTransaction;
}scheduling;

