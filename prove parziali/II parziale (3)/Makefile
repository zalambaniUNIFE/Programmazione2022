utenti: main.o listaUtenti.o
	gcc -g -o utenti main.o listaUtenti.o

main.o: main.c listaUtenti.h
	gcc -c -g main.c

listaUtenti.o: listaUtenti.c listaUtenti.o
	gcc -c -g listaUtenti.c