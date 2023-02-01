typedef struct transacao
{
    int t_chegada;
    int id;
    char operacao;
    char atributo;
    struct transacao *ordem_por_tempo;  //Ordem cronologica em que apenas essa transacao aparece  
} transacao;

typedef struct idEscalonamento
{
    int idEsc;
    int commitado;
} idEscalonamento;


// Agenda com todas as transacoes por ordem de chegada
typedef struct agendamento
{   
    int tamanho;
    transacao *lista_transacoes;
    idEscalonamento *lista_escalonamentos;
    
} agendamento;

int cria_transacao(transacao *t);

int imprime_transacao(transacao *t);

int cria_agendamento(agendamento *S);

int agendamento_vazio(agendamento *S);

void destroi_agendamento(agendamento *S);

int insere_agendamento(transacao *t_nova, agendamento *S);

void imprime_agendamento(agendamento *S);