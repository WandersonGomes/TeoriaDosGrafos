#ifndef __GRAFO_LISTA__

#define __GRAFO_LISTA__
#include "grafo_tipos.h"

GrafoListaAdjacencia* criarGrafoListaAdjacencia(int quantidade_vertices, int eh_direcionado);
void adicionarArestaGrafoListaAdjacencia(GrafoListaAdjacencia* grafo, Aresta aresta);
void imprimirGrafoListaAdjacencia(GrafoListaAdjacencia* grafo);
void destruirGrafoListaAdjacencia(GrafoListaAdjacencia* grafo);

#endif