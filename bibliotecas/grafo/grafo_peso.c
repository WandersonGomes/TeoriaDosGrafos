#include <stdio.h>
#include <stdlib.h>
#include "grafo_peso.h"

GrafoMatrizPesos* criarGrafoMatrizPesos(int quantidade_vertices, int eh_direcionado) {
    GrafoMatrizPesos* grafo = (GrafoMatrizPesos*) malloc(sizeof(GrafoMatrizPesos));

    if (grafo != NULL) {
        grafo->quantidade_vertices = quantidade_vertices;
        grafo->eh_direcionado = eh_direcionado;
        grafo->matriz_pesos = criarMatrizDoubleDinamica(quantidade_vertices, quantidade_vertices);
    }

    return grafo;
}

void adicionarArestaGrafoMatrizPesos(GrafoMatrizPesos* grafo, Aresta aresta) {
    grafo->matriz_pesos[aresta.vertice_origem][aresta.vertice_destino] = aresta.peso;

    if (grafo->eh_direcionado)
        grafo->matriz_pesos[aresta.vertice_destino][aresta.vertice_origem] = aresta.peso;
}

void imprimirGrafoMatrizPesos(GrafoMatrizPesos* grafo) {
        printf("TIPO: ");
    if (grafo->eh_direcionado)
        puts("GRAFO DIRECIONADO (DIGRAFO)");
    else 
        puts("GRAFO NAO DIRECIONADO");
    
    printf("\nVERTICES: {");
    for (int i = 1; i <= grafo->quantidade_vertices; i++)
        (i != 1) ? printf(", %d", i) : printf("%d", i);
    puts("}");

    puts("\nMATRIZ PESOS:"); 
    imprimirMatrizDoubleDinamica(grafo->matriz_pesos, grafo->quantidade_vertices, grafo->quantidade_vertices);
}

void destruirGrafoMatrizPesos(GrafoMatrizPesos* grafo) {
    destruirMatrizDoubleDinamica(grafo->matriz_pesos, grafo->quantidade_vertices);
    free(grafo);
}
