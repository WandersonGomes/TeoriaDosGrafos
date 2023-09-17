#include <stdio.h>
#include <stdlib.h>
#include "../lista/lista.h"
#include "grafo_lista.h"

GrafoListaAdjacencia* criarGrafoListaAdjacencia(int quantidade_vertices, int eh_direcionado) {
    GrafoListaAdjacencia* grafo = (GrafoListaAdjacencia*) malloc(sizeof(GrafoListaAdjacencia));
    
    if (grafo != NULL) {
        grafo->eh_direcionado = eh_direcionado;
        grafo->quantidade_vertices = quantidade_vertices;
        grafo->lista_adjacencia = (Lista**) malloc(sizeof(Lista*) * quantidade_vertices);

        for (int i = 0; i < quantidade_vertices; i++)
            grafo->lista_adjacencia[i] = criarLista();
    }
    
    return grafo;
}

void adicionarArestaGrafoListaAdjacencia(GrafoListaAdjacencia* grafo, Aresta aresta) {
    if (grafo->eh_direcionado) {
        inserirListaOrdenadoCrescente(
            grafo->lista_adjacencia[aresta.vertice_origem], 
            criarDado(aresta.vertice_destino, aresta.peso)
        );
    } else {
        inserirListaOrdenadoCrescente(
            grafo->lista_adjacencia[aresta.vertice_origem], 
            criarDado(aresta.vertice_destino, aresta.peso)
        );

        inserirListaOrdenadoCrescente(
            grafo->lista_adjacencia[aresta.vertice_destino], 
            criarDado(aresta.vertice_origem, aresta.peso)
        );
    }
}

void imprimirGrafoListaAdjacencia(GrafoListaAdjacencia* grafo) {
    printf("TIPO: ");
    if (grafo->eh_direcionado)
        puts("GRAFO DIRECIONADO (DIGRAFO)");
    else 
        puts("GRAFO NAO DIRECIONADO");
    
    printf("\nVERTICES: {");
    for (int i = 1; i <= grafo->quantidade_vertices; i++)
        (i != 1) ? printf(", %d", i) : printf("%d", i);
    puts("}");

    puts("\nLISTA ADJACENCIA:"); 
    for (int i = 0; i < grafo->quantidade_vertices; i++)
        grafo->lista_adjacencia[i];
}

void destruirGrafoListaAdjacencia(GrafoListaAdjacencia* grafo) {
    for (int i = 0; i < grafo->quantidade_vertices; i++)
        destruirLista(grafo->lista_adjacencia[i]);

    free(grafo->lista_adjacencia);

    free(grafo);
}

