#ifndef __GRAFO_INCIDENCIA__

#define __GRAFO_INCIDENCIA__
#include "grafo_tipos.h"

/*
    DEFINICAO ADOTADA NESTA IMPLEMENTACAO:
    Uma matriz de incidencia e uma matriz X[v,e] tal que:
    
    X[v, e] = 0, se e nao incide em v
    X[v, e] = 1, se e incide em v
    X[v, e] = 2, se e e lacete em v

    onde v pertence a V, e e pertence a A.

    Obs.:
    Se tivermos um grafo orientado(digrafo):
    X[v, e] = 0 nao incide em v
    X[v, e] = -1 se v e extremidade inicial de e e nao e lacete em v
    X[v, e] = 1 se v e extremidade final de e e nao e lacete em v
    X[v, e] = 2 se e e lacete em v
*/

GrafoMatrizIncidencia* criarGrafoMatrizIncidencia(int quantidade_vertices, int quantidade_arestas, int eh_direcionado);
void adicionarArestaGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo, Aresta aresta, int indice_aresta);
void imprimirGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo);
void destruirGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo);

#endif