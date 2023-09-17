#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/matriz/matriz.h"
#include "grafo_incidencia.h"

GrafoMatrizIncidencia* criarGrafoMatrizIncidencia(int quantidade_vertices, int quantidade_arestas, int eh_direcionado) {
    GrafoMatrizIncidencia* grafo = (GrafoMatrizIncidencia*) malloc(sizeof(GrafoMatrizIncidencia));

    if (grafo != NULL) {
        grafo->quantidade_vertices = quantidade_vertices;
        grafo->quantidade_arestas = quantidade_arestas;
        grafo->eh_direcionado = eh_direcionado;
        grafo->matriz_incidencia = criarMatrizIntDinamica(quantidade_vertices, quantidade_arestas);
    }

    return grafo;
}

void adicionarArestaGrafoMatrizAdjacencia(GrafoMatrizIncidencia* grafo, Aresta aresta, int indice_aresta) {
    if (grafo->eh_direcionado) {
        if (aresta.vertice_origem != aresta.vertice_destino)
            grafo->matriz_incidencia[aresta.vertice_destino][indice_aresta] = 1;
        else
            grafo->matriz_incidencia[aresta.vertice_destino][indice_aresta] = 2;
    } else {
        if (aresta.vertice_origem = aresta.vertice_destino)
            grafo->matriz_incidencia[aresta.vertice_destino][indice_aresta] = 2;
        else {
            grafo->matriz_incidencia[aresta.vertice_origem][indice_aresta] = -1;
            grafo->matriz_incidencia[aresta.vertice_destino][indice_aresta] = 1;
        }
    }
}

void imprimirGrafoMatrizAdjacencia(GrafoMatrizIncidencia* grafo) {
    printf("TIPO: ");
    if (grafo->eh_direcionado)
        puts("GRAFO DIRECIONADO (DIGRAFO)");
    else 
        puts("GRAFO NAO DIRECIONADO");
    
    printf("\nVERTICES: {");
    for (int i = 1; i <= grafo->quantidade_vertices; i++)
        (i != 1) ? printf(", %d", i) : printf("%d", i);
    puts("}");

    puts("\nMATRIZ INCIDENCIA:"); 
    imprimirMatrizIntDinamica(grafo->matriz_incidencia, grafo->quantidade_vertices, grafo->quantidade_arestas);
}

void destruirGrafoMatrizAdjacencia(GrafoMatrizIncidencia* grafo) {
    destruirMatrizIntDinamica(grafo->matriz_incidencia, grafo->quantidade_vertices);
    free(grafo);
}
