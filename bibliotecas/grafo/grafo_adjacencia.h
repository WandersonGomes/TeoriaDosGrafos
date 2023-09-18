#ifndef __GRAFO_ADJACENCIA__

#define __GRAFO_ADJACENCIA__
#include "grafo_tipos.h"

/*
    DEFINICAO ADOTADA NESTA IMPLEMENTACAO:
    -> Uma matriz A = [a_ij] quadrada de ordem n e denominada matriz de adjacencia
    de G = (V, A) quando:
        a_ij = 1, se existe (i, j) pertencente a M
        a_ij = 0 em caso contrario
*/

GrafoMatrizAdjacencia* criarGrafoMatrizAdjacencia(int quantidade_vertices, int eh_direcionado);
void adicionarArestaGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo, Aresta aresta);
void imprimirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo);
void destruirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo);

#endif