#ifndef __GRAFO_ADJACENCIA__
#define __GRAFO_ADJACENCIA__

typedef struct {
    int vertice_origem;
    int vertice_destino;
    double peso;
} Aresta;

typedef struct {
    unsigned int quantidade_vertices;
    unsigned char eh_direcionado;
    int** matriz_adjacencia;
} GrafoMatrizAdjacencia;

GrafoMatrizAdjacencia* criarGrafoMatrizAdjacencia(int quantidade_vertices, int eh_direcionado);
void adicionarArestaGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo, Aresta aresta);
void imprimirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo);
void destruirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo);

#endif