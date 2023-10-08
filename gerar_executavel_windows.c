#include <stdio.h>
#include <stdlib.h>

int main() {
    system("gcc ./bibliotecas/grafo/grafo_adjacencia.c -c grafo_adjacencia.o");
    system("gcc ./bibliotecas/grafo/grafo_incidencia.c -c grafo_incidencia.o");
    system("gcc ./bibliotecas/grafo/grafo_lista.c -c grafo_lista.o");
    system("gcc ./bibliotecas/grafo/grafo_peso.c -c grafo_peso.o");
    system("gcc ./bibliotecas/grafo/grafo_vetorial.c -c grafo_vetorial.o");

    system("gcc ./bibliotecas/matriz/matriz.c -c matriz.o");
    system("gcc ./bibliotecas/lista/lista.c -c lista.o");
    system("gcc main.c -c main.o");

    system("gcc main.o grafo_adjacencia.o grafo_incidencia.o grafo_lista.o grafo_peso.o grafo_vetorial.o matriz.o lista.o -o programa-grafo");

    system ("del *.o");

    return 0;
}