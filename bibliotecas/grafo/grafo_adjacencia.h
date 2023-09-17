#ifndef __GRAFO_ADJACENCIA__
#define __GRAFO_ADJACENCIA__
#include "grafo_tipos.h"

/*
    DEFINICAO ADOTADA NESTA IMPLEMENTACAO:
    Matriz de Adjacência é uma matriz n x n, denotada por X = [x_ij] e definida como:
        x_ij = 1, se existe uma aresta entre os vertices vi e vj,
        x_ij = 0, caso contrario.

    Obs.:
    Se tivermos um grafo orientado(digrafo):
        x_ij = 1, se existe uma aresta direcionada do vertice vi para o vertice vj,
        x_ij = 0, caso contrario.  
*/

GrafoMatrizAdjacencia* criarGrafoMatrizAdjacencia(int quantidade_vertices, int eh_direcionado);
void adicionarArestaGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo, Aresta aresta);
void imprimirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo);
void destruirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo);

#endif