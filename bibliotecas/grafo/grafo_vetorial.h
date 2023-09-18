#ifndef __GRAFO_VETORIAL__

#define __GRAFO_VETORIAL__
#include "grafo_tipos.h"

/*
    DEFINICAO ADOTADA NESTA IMPLEMENTACAO:
    -> Dois vetores, V e W, com dimensoes n e soma dos graus dos vertices,
    respectivamente.
    -> Cada elemento i do vetor V registra o grau do vertice i
    -> Os elementos de W correspondem aos vizinhos do vertice representados
    em V
*/

GrafoVetorial* criarGrafoVetorial(int quantidade_vertices, int eh_direcionado);
void adicionarArestaGrafoVetorial(GrafoVetorial* grafo, Aresta aresta);
void imprimirGrafoVetorial(GrafoVetorial* grafo);
void destruirGrafoVetorial(GrafoVetorial* grafo);

#endif