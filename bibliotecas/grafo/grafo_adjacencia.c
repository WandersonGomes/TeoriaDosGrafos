#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/matriz/matriz.h"
#include "grafo_adjacencia.h"

GrafoMatrizAdjacencia* criarGrafoMatrizAdjacencia(int quantidade_vertices, int eh_direcionado) {
    GrafoMatrizAdjacencia* grafo = (GrafoMatrizAdjacencia*) malloc(sizeof(GrafoMatrizAdjacencia));

    if (grafo != NULL) {
        grafo->quantidade_vertices = quantidade_vertices;
        grafo->eh_direcionado = eh_direcionado;
        grafo->matriz_adjacencia = criarMatrizIntDinamica(quantidade_vertices, quantidade_vertices);
    }

    return grafo;
}

void adicionarArestaGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo, Aresta aresta) {
    grafo->matriz_adjacencia[aresta.vertice_origem][aresta.vertice_destino] = 1;

    if (grafo->eh_direcionado)
        grafo->matriz_adjacencia[aresta.vertice_destino][aresta.vertice_origem] = 1;
}

void imprimirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo) {
    printf("TIPO: ");
    if (grafo->eh_direcionado)
        puts("GRAFO DIRECIONADO (DIGRAFO)");
    else 
        puts("GRAFO NAO DIRECIONADO");
    
    printf("\nVERTICES: {");
    for (int i = 1; i <= grafo->quantidade_vertices; i++)
        (i != 1) ? printf(", %d", i) : printf("%d", i);
    puts("}");

    puts("\nMATRIZ ADJACENCIA:"); 
    imprimirMatrizIntDinamica(grafo->matriz_adjacencia, grafo->quantidade_vertices, grafo->quantidade_vertices);
}

void destruirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo) {
    destruirMatrizIntDinamica(grafo->matriz_adjacencia, grafo->quantidade_vertices);
    free(grafo);
}
