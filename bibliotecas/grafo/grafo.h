#ifndef __GRAFO__
#define __GRAFO__

#define DIRECIONADO 1
#define NAO_DIRECIONADO 0

typedef struct {
    int vertice_origem;
    int vertice_destino;
    double peso;
} Aresta;

void imprimirAresta(Aresta aresta);

//GRAFO - MATRIZ ADJACENCIA
typedef struct {
    int direcionado;
    int quantidade_vertices;
    double** matriz_adjacencia;
} GrafoMatrizAdjacencia;

GrafoMatrizAdjacencia* criarGrafoMatrizAdjacencia(int quantidade_vertices, int direcionado);
void adicionarArestaGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo, Aresta aresta);
void imprimirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo);
void destruirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo);

//GRAFO - MATRIZ DE INCIDENCIA
typedef struct {
    int direcionado;
    int quantidade_vertices;
    int quantidade_arestas;
    double** matriz_incidencia;
} GrafoMatrizIncidencia;

GrafoMatrizIncidencia* criarGrafoMatrizIncidencia(int quantidade_vertices, int quantidade_arestas, int direcionado);
void adicionarArestaGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo, Aresta aresta, int numero);
void imprimirGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo);
void destruirGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo);

#endif