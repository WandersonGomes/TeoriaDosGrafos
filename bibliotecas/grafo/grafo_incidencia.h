#ifndef __GRAFO_ADJACENCIA__
#define __GRAFO_ADJACENCIA__

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

typedef struct {
    int vertice_origem;
    int vertice_destino;
    double peso;
} Aresta;

typedef struct {
    unsigned int quantidade_vertices;
    unsigned int quantidade_arestas;
    unsigned char eh_direcionado;
    int** matriz_incidencia;
} GrafoMatrizIncidencia;

GrafoMatrizIncidencia* criarGrafoMatrizIncidencia(int quantidade_vertices, int quantidade_arestas, int eh_direcionado);
void adicionarArestaGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo, Aresta aresta);
void imprimirGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo);
void destruirGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo);

#endif