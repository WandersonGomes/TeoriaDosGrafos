#ifndef __GRAFO_PESO__

#define __GRAFO_PESO__
#include "grafo_tipos.h"

GrafoMatrizPesos* criarGrafoMatrizPesos(int quantidade_vertices, int eh_direcionado);
void adicionarArestaGrafoMatrizPesos(GrafoMatrizPesos* grafo, Aresta aresta);
void imprimirGrafoMatrizPesos(GrafoMatrizPesos* grafo);
void destruirGrafoMatrizPesos(GrafoMatrizPesos* grafo);

#endif