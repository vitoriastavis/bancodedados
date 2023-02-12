#ifndef __SERIALIZAVELCONFLITO_H__
#define __SERIALIZAVELCONFLITO_H__

#include "utils.h"


/*!
    @brief Função implementa algoritmo de teste de serializade por conflito.
    @param a: Ponteiro para acesso à estrutura de agenda
    @return Verdadeiro (1) ou Falso(0).
*/
int eh_serializavel(Agenda *a);

#endif // __SERIALIZAVELCONFLITO_H__