compile:
	gcc ./bibliotecas/grafo/grafo_adjacencia.c -c grafo_adjacencia.o
	gcc ./bibliotecas/grafo/grafo_incidencia.c -c grafo_incidencia.o
	gcc ./bibliotecas/grafo/grafo_lista.c -c grafo_lista.o
	gcc ./bibliotecas/grafo/grafo_peso.c -c grafo_peso.o
	gcc ./bibliotecas/grafo/grafo_vetorial.c -c grafo_vetorial.o

	gcc ./bibliotecas/matriz/matriz.c -c matriz.o
	gcc ./bibliotecas/lista/lista.c -c lista.o
	gcc main.c -c main.o

	gcc main.o grafo_adjacencia.o grafo_incidencia.o grafo_lista.o grafo_peso.o grafo_vetorial.o matriz.o lista.o -o executavel

clear:
	rm *.o

run-ma-nao-direcionado:
	./executavel read dados_teste.g show -ma
run-ma-direcionado:
	./executavel read dados_teste.g show -ma -d

run-mi-nao-direcionado:
	./executavel read dados_teste.g show -mi
run-mi-direcionado:
	./executavel read dados_teste.g show -mi -d

run-la-nao-direcionado:
	./executavel read dados_teste.g show -la
run-la-direcionado:
	./executavel read dados_teste.g show -la -d

run-mp-nao-direcionado:
	./executavel read dados_teste.g show -mp
run-mp-direcionado:
	./executavel read dados_teste.g show -mp -d

run-ve-nao-direcionado:
	./executavel read dados_teste.g show -ve
run-ve-direcionado:
	./executavel read dados_teste.g show -ve -d