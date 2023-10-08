compile:
	gcc ./bibliotecas/grafo/grafo_adjacencia.c -c grafo_adjacencia.o
	gcc ./bibliotecas/grafo/grafo_incidencia.c -c grafo_incidencia.o
	gcc ./bibliotecas/grafo/grafo_lista.c -c grafo_lista.o
	gcc ./bibliotecas/grafo/grafo_peso.c -c grafo_peso.o
	gcc ./bibliotecas/grafo/grafo_vetorial.c -c grafo_vetorial.o

	gcc ./bibliotecas/matriz/matriz.c -c matriz.o
	gcc ./bibliotecas/lista/lista.c -c lista.o
	gcc main.c -c main.o

	gcc main.o grafo_adjacencia.o grafo_incidencia.o grafo_lista.o grafo_peso.o grafo_vetorial.o matriz.o lista.o -o programa-grafo

clear:
	rm *.o

run-ma-nao-direcionado:
	./programa-grafo read inst-5 show -ma
	./programa-grafo read inst-5.2 show -ma
	./programa-grafo read inst-5.3 show -ma
	./programa-grafo read inst-7 show -ma
	./programa-grafo read inst-13 show -ma

run-ma-direcionado:
	./programa-grafo read dados_teste.g show -ma -d

run-mi-nao-direcionado:
	./programa-grafo read dados_teste.g show -mi
run-mi-direcionado:
	./programa-grafo read dados_teste.g show -mi -d

run-la-nao-direcionado:
	./programa-grafo read dados_teste.g show -la
run-la-direcionado:
	./programa-grafo read dados_teste.g show -la -d

run-mp-nao-direcionado:
	./programa-grafo read dados_teste.g show -mp
run-mp-direcionado:
	./programa-grafo read dados_teste.g show -mp -d

run-ve-nao-direcionado:
	./programa-grafo read dados_teste.g show -ve
run-ve-direcionado:
	./programa-grafo read dados_teste.g show -ve -d