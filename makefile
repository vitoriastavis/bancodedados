CC = gcc

INC=./includes
SRC=./src

CFLAGS = -Wall

executable = main.c $(SRC)/transacao.c $(SRC)/utils.c $(SRC)/grafo.c $(SRC)/agenda.c $(SRC)/equivalente_visao.c $(SRC)/serializavel_conflito.c
library = $(INC)/transacao.h $(INC)/utils.h $(INC)/grafo.h $(INC)/agenda.h $(INC)/equivalente_visao.h $(INC)/serializavel_conflito.h

# Define regra default
all: escalona

# escalona: $(executable) $(library)
escalona: $(executable)
	$(CC) -g $(CFLAGS) $(executable) -o escalona

# Remove arquivos temporários
clean:
	-rm -f *~ *.o

# Remove extra código fonte original
purge: clean
	-rm -f escalona