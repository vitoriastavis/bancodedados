#include "../includes/utils.h"

#define MAX_TRANSACOES 100
#define MAX_LENGTH 2

Escalonamento *cria_escalonamento()
{
    Escalonamento *e = malloc(sizeof(Escalonamento));
    e->total_agendas = 0;
    e->lista_escalonamento = malloc(MAX_TRANSACOES*sizeof(Agenda));

    return e;
}

void le_salva_entradas(Escalonamento *e)
{
    int tempo, id;
    char op[MAX_LENGTH];
    char atr[MAX_LENGTH];

    Agenda *a_aux = cria_agenda();
    Transacao *transacao = NULL;

    /* Vetor das transacoes ativas e numero de transacoes ativas */
    int ativas[MAX_TRANSACOES];
    int tam_ativas = 0;

    while (!feof(stdin)){

        fscanf(stdin, "%d", &tempo);

        /* Para caso tenha linha em branco ou arquivo tenha terminado */
        if (tempo == -1)
            break;

        /* Le linha da transacao */
        fscanf(stdin, "%d", &id);
        fscanf(stdin, "%s", op);
        fscanf(stdin, "%s", atr);

        /* Adiciona informacoes da transacao na estrutura de transacao */
        transacao = cria_transacao(tempo, id, op[0], atr[0]);

        adiciona_info_agenda(transacao, a_aux);

        /* Atualiza numero de transacoes ativas, se uma transacao deu commit, esse numero eh diminuido  */
        if(op[0] == 'C') {
            remove_ativas(ativas, &tam_ativas, id);
        }
        else{
            adiciona_ativas(ativas, &tam_ativas, id);
        }

        /* Se todas as transacoes desta agenda terminaram */
        if (tam_ativas == 0) {
            /* Salva agenda */      
            e->lista_escalonamento[e->total_agendas] = a_aux;
            e->lista_escalonamento[e->total_agendas]->lista_ids_unicos = salva_ids(a_aux);
            e->total_agendas++;

            /* Zera variaveis auxiliares, iniciando nova agenda */
            a_aux = cria_agenda();
        }               
    } 
    free(a_aux);
    free(transacao);
}

void remove_ativas(int *ativas, int *tam, int id)
{
    int tamanho = *tam;
    for (int i = 0; i < tamanho; i ++) {
        if (ativas[i] == id) {
            *tam = tamanho - 1;
            for(int j = i; j < tamanho; j++) {
                ativas[j] = ativas[j + 1];
            }
            break;
        }
    }
}

void adiciona_ativas(int *ativas, int *tam, int id)
{
    int tamanho = *tam;
    for (int i = 0; i < tamanho; i++) {
        if (ativas[i] == id) {
            return;
        }
    }
    ativas[tamanho] = id;
    *tam += 1;
}

void imprime_resposta_final(Agenda *a, int id_agenda, int serializavel, int equivalente)
{
    /* Imprime identificador da agenda  */
    printf("%d ", id_agenda + 1);

    /* Imprime lista de transacoes desta agenda */
    for(int i = 0; i < a->num_transacoes; i++) {
        printf("%d", a->lista_ids_unicos[i]);
        if(i + 1 != a->num_transacoes) {
            printf(",");
        }
    }

    /* Imprime resultado do algoritmo de garantia de serialidade   */
    serializavel ? printf(" NS "): printf(" SS ");

    /* Imprime resultado do algoritmo de teste de equivalencia de visao   */
    equivalente ? printf("SV") : printf("NV");

    printf("\n");
}
