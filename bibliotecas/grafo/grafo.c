#include "../matriz/matriz.h"
#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define SUCESSO 1

void imprimirAresta(Aresta aresta) {
    printf("Aresta: (%d, %d, %g)\n", aresta.vertice_origem, aresta.vertice_destino, aresta.peso);
}

//GRAFO - MATRIZ DE ADJACENCIA
GrafoMatrizAdjacencia* criarGrafoMatrizAdjacencia(int quantidade_vertices, int direcionado) {
    GrafoMatrizAdjacencia* grafo = (GrafoMatrizAdjacencia*) malloc(sizeof(GrafoMatrizAdjacencia));

    if (grafo != NULL) {
        grafo->direcionado = (direcionado == DIRECIONADO) ? DIRECIONADO : NAO_DIRECIONADO;
        grafo->quantidade_vertices = quantidade_vertices;
        grafo->matriz_adjacencia = criarMatrizDinamica(quantidade_vertices, quantidade_vertices);
    }

    return grafo;
}

int verificarPertinenciaAresta(int quantidade_vertices, Aresta aresta) {
    if (aresta.vertice_origem < 1) return ERROR;
    if (aresta.vertice_destino < 1) return ERROR;
    if (aresta.vertice_origem > quantidade_vertices) return ERROR;
    if (aresta.vertice_destino > quantidade_vertices) return ERROR;

    return SUCESSO;
}

void adicionarArestaGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo, Aresta aresta) {
    if (verificarPertinenciaAresta(grafo->quantidade_vertices, aresta) == SUCESSO) {
        int origem  = aresta.vertice_origem - 1, 
            destino = aresta.vertice_destino - 1;

        grafo->matriz_adjacencia[origem][destino] = aresta.peso;

        if (grafo->direcionado == NAO_DIRECIONADO)
            grafo->matriz_adjacencia[destino][origem] = aresta.peso;

    } else {
        puts("ERROR: aresta impossivel de ser adicionada!");
    }
}

void imprimirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo) {
    if (grafo->direcionado == DIRECIONADO)
        puts("GRAFO DIRECIONADO:");
    else 
        puts("GRAFO NAO DIRECIONADO:");
    
    puts("MATRIZ DE ADJACENCIA:");
    imprimirMatrizDinamica(grafo->matriz_adjacencia, grafo->quantidade_vertices, grafo->quantidade_vertices);
}

void destruirGrafoMatrizAdjacencia(GrafoMatrizAdjacencia* grafo) {
    destruirMatrizDinamica(grafo->matriz_adjacencia, grafo->quantidade_vertices);
    free(grafo);
}

//GRAFO - MATRIZ DE INCIDENCIA
GrafoMatrizIncidencia* criarGrafoMatrizIncidencia(int quantidade_vertices, int quantidade_arestas, int direcionado) {
    GrafoMatrizIncidencia* grafo = (GrafoMatrizIncidencia*) malloc(sizeof(GrafoMatrizIncidencia));

    if (grafo != NULL) {
        grafo->direcionado = direcionado;
        grafo->quantidade_vertices = quantidade_vertices;
        grafo->quantidade_arestas = quantidade_arestas;
        grafo->matriz_incidencia = criarMatrizDinamica(quantidade_vertices, quantidade_arestas);
    }

    return grafo;
}

void adicionarArestaGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo, Aresta aresta, int numero) {
    if (verificarPertinenciaAresta(grafo->quantidade_vertices, aresta) == SUCESSO) {
        if ((numero >= 1) && (numero <= grafo->quantidade_arestas)) {
            int origem = aresta.vertice_origem - 1,
                destino = aresta.vertice_destino - 1;

            numero--;
            grafo->matriz_incidencia[origem][numero] = aresta.peso;
            grafo->matriz_incidencia[destino][numero] = (grafo->direcionado == NAO_DIRECIONADO) ? aresta.peso : -aresta.peso;
        } else {
            puts("ERROR: numero da aresta fora do intervalo!");
        }
    } else {
        puts("ERROR: aresta impossivel de ser adicionada!");
    }
}

void imprimirGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo) {
    if (grafo->direcionado == DIRECIONADO)
        puts("GRAFO DIRECIONADO:");
    else 
        puts("GRAFO NAO DIRECIONADO:");
    
    puts("MATRIZ DE INCIDENCIA:");
    imprimirMatrizDinamica(grafo->matriz_incidencia, grafo->quantidade_vertices, grafo->quantidade_arestas);
}

void destruirGrafoMatrizIncidencia(GrafoMatrizIncidencia* grafo) {
    destruirMatrizDinamica(grafo->matriz_incidencia, grafo->quantidade_vertices);
    free(grafo);
}