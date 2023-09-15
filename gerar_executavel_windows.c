#include <stdio.h>
#include <stdlib.h>

int main() {
    system("gcc ./bibliotecas/grafo/grafo.c -c grafo.o");
    system("gcc ./bibliotecas/matriz/matriz.c -c matriz.o");
    system("gcc main.c -c main.o");
    system("gcc main.o grafo.o matriz.o -o executavel_windows");

    system ("del grafo.o");
    system ("del matriz.o");
    system ("del main.o");

    return 0;
}