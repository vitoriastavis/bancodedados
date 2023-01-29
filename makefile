# Leticia Fontanelli Straube de Souza | GRR20190569 
# Vitória Stavis | GRR2020
CC = gcc

INC=./includes
SRC=./scr

CFLAGS = -Wall

executable = main.c $(SRC)/utils.c
library = $(INC)/transaction.h $(INC)/utils.h

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