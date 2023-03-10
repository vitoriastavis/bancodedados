CC = gcc

INC=./includes
SRC=./src

CFLAGS = -Wall

executable = main.c $(SRC)/transacao.c $(SRC)/utils.c $(SRC)/grafo.c $(SRC)/agenda.c $(SRC)/serializavelConflito.c
library = $(INC)/transacao.h $(INC)/utils.h $(INC)/grafo.h $(INC)/agenda.h $(INC)/serializavelConflito.h

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