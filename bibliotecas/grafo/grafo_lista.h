#include "../lista/lista.h"

#ifndef __GRAFO_LISTA__
#define __GRAFO_LISTA__

typedef struct {
    int vertice_origem;
    int vertice_destino;
    int peso;
} Aresta;

typedef struct {
    int eh_direcionado;
    int quantidade_vertices;
    Lista** lista_adjacencia;
} GrafoListaAdjacencia;

GrafoListaAdjacencia* criarGrafoListaAdjacencia(int quantidade_vertices, int eh_direcionado);
void adicionarArestaGrafoMatrizIncidencia(GrafoListaAdjacencia* grafo, Aresta aresta);
void imprimirGrafoMatrizIncidencia(GrafoListaAdjacencia* grafo);
void destruirGrafoMatrizIncidencia(GrafoListaAdjacencia* grafo);

#endif