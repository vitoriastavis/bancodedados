#include <stdio.h>
#include <stdlib.h>
#include "../includes/agenda.h"

Agenda *cria_agenda()
{
    Agenda *a = malloc(sizeof(Agenda));
    
    a->num_transacoes = 0;
    a->tam = 0;
    a->inicio = NULL;
    a->fim = NULL;
    a->lista_ids_unicos = NULL;

    return a;
}

void adiciona_info_agenda(Transacao *t, Agenda *a)
{
    if(a->inicio == NULL && a->fim == NULL)
    {
        a->inicio = t;
        a->fim = t;
        a->tam++;
        return;
    }
    else{
        a->fim->proximo = t;
        t->anterior = a->fim;
        a->fim = t;
        a->tam++;
    }
}

int *salva_ids(Agenda *agenda)
{
    int tam = agenda->tam;
    int *existentes = malloc(tam * sizeof(int));
    Transacao *aux = agenda->inicio;
    int eh_unico;
    int chave;
    short int j;


    for (int i = 0; i < tam; i++){
        eh_unico = 1;
        for(int j = 0; j < agenda->num_transacoes; j++){
            if(existentes[j] == aux->identificador){
                eh_unico = 0;
            }
        }

        if(eh_unico){
            existentes[agenda->num_transacoes] = aux->identificador;
            agenda->num_transacoes++;
        }
        aux = aux->proximo;
    }

    /* Ordena por Insertion Sort */
    for (int i = 0; i < agenda->num_transacoes; i++){
        chave = existentes[i];
        j = i - 1;
        while (j >= 0 && existentes[j] > chave)
        {
            existentes[j+1] = existentes[j];
            j = j - 1;
        }
        existentes[j+1] = chave;
    }

    free(aux);
    return existentes;
}

void imprime_ids(Agenda *a)
{
    printf("IDs desta agenda: ");
    for(int k = 0; k < a->num_transacoes; k++)
    {
        printf("%d ", a->lista_ids_unicos[k]);
    }   
}

void imprime_agenda_completa(Escalonamento *e)
{
    for(int j = 0; j < e->total_agendas; j++)
    {
        Transacao *aux = e->lista_escalonamento[j]->inicio;
        
        printf("\n\n ---- Informacoes da agenda %d --- \n", j);
        printf("Tamanho: %d\nNum transacoes: %d \n", e->lista_escalonamento[j]->tam, e->lista_escalonamento[j]->num_transacoes);
        imprime_ids(e->lista_escalonamento[j]);
        printf("\nOrdem de transcoes processadas: ");

        for(int i = 0; i < e->lista_escalonamento[j]->tam; i++)
        {
            printf("%d ", aux->identificador);
            aux = aux->proximo;
        }
    }
    printf("\n");
}