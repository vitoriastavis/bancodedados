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
    int tam_transacao;
} idEscalonamento;

typedef struct agendamento
{   
    int qtd_transacoes;
    transacao **lista_transacoes; // lista com todas as transacoes por ordem de chegada
    idEscalonamento *lista_escalonamentos; // lista com ids unicos das transacoes
} agendamento;

int guarda_transacao(transacao *t, agendamento *S, int pos);

int imprime_transacao(transacao *t);

int cria_agendamento(agendamento *S);

int agendamento_vazio(agendamento *S);

void destroi_agendamento(agendamento *S);

int insere_agendamento(transacao *t_nova, agendamento *S);

void imprime_agendamento(agendamento *S);

void guarda_indices_unicos(agendamento *S);

int verifica_existencia_id(int id, agendamento *S);