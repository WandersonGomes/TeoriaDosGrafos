compile:
	gcc ./bibliotecas/grafo/grafo.c -c grafo.o
	gcc ./bibliotecas/matriz/matriz.c -c matriz.o
	gcc ./bibliotecas/lista/lista.c -c lista.o
	gcc main.c -c main.o
	gcc main.o grafo.o matriz.o lista.o -o executavel
clear:
	rm *.o

run-ma-nao-direcionado:
	./executavel read dados_teste.g show -ma
run-ma-direcionado:
	./executavel read dados_teste.g show -ma -d