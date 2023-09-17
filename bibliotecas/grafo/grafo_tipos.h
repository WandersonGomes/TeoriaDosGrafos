#ifndef __GRAFO_TIPOS__
#define __GRAFO_TIPOS__

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

typedef struct {
    unsigned int quantidade_vertices;
    unsigned int quantidade_arestas;
    unsigned char eh_direcionado;
    int** matriz_incidencia;
} GrafoMatrizIncidencia;

typedef struct {
    int quantidade_vertices;
    int eh_direcionado;
    double** matriz_pesos;
} GrafoMatrizPesos;

#endif