typedef struct transacao
{
    int t_chegada;
    int id;
    char operacao;
    char atributo;
    struct transacao *prox_tempo;
    struct transacao *ant_tempo;
    struct transacao *prox_op;
    struct transacao *ant_op;
    short int commitado;
    
} transacao;

// Agenda com todas as transacoes
typedef struct agendamento
{   
    int tamanho;
    struct transacao *lista_transacoes;
} agendamento;

int cria_transacao(transacao *t);

int imprime_transacao(transacao *t);

int cria_agendamento(agendamento *S);

int agendamento_vazio(agendamento *S);

void destroi_agendamento(agendamento *S);

int insere_agendamento(transacao *t_nova, agendamento *S);

void imprime_agendamento(agendamento *S);