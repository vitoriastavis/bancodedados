// Agenda com todas as transacoes
typedef struct agendamento
{   
    int tamanho;
    transacao *inicio;
} agendamento;

typedef struct transacao
{
    int t_chegada;
    int id;
    char op;
    char atributo;
    transacao *prox;
} transacao;

// Guarda se transacao foi commitada ou nao
typedef struct idtransacao {	
	int id;								
	short int isCommited;					
} idtransacao;

