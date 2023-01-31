typedef struct transacao
{
    int t_chegada;
    int id;
    char operacao;
    char atributo;
    struct transacao *prox;
} transacao;

// Guarda se transacao foi commitada ou nao
typedef struct idtransacao {	
	int id;								
	short int isCommited;					
} idtransacao;

// Agenda com todas as transacoes
typedef struct agendamento
{   
    int tamanho;
    struct transacao *inicio;
} agendamento;

int cria_transacao(transacao *t);

int imprime_transacao(transacao *t);

int cria_agendamento(agendamento *S);

int agendamento_vazio(agendamento *S);

void destroi_agendamento(agendamento *S);

int insere_agendamento(transacao *t_nova, agendamento *S);

void imprime_agendamento(agendamento *S);