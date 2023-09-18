#include <stdio.h>
#include <stdlib.h>
#include "grafo_vetorial.h"

GrafoVetorial* criarGrafoVetorial(int quantidade_vertices, int eh_direcionado) {
    GrafoVetorial* grafo = (GrafoVetorial*) malloc(sizeof(GrafoVetorial));
    
    if (grafo != NULL) {
        grafo->eh_direcionado = eh_direcionado;
        grafo->quantidade_vertices = quantidade_vertices;
        grafo->lista_adjacencia = (Lista**) malloc(sizeof(Lista*) * quantidade_vertices);

        for (int i = 0; i < quantidade_vertices; i++)
            grafo->lista_adjacencia[i] = criarLista();
    }
    
    return grafo;
}

void adicionarArestaGrafoVetorial(GrafoVetorial* grafo, Aresta aresta) {
    inserirListaOrdenadoCrescente(
        grafo->lista_adjacencia[aresta.vertice_origem], 
        criarDado(aresta.vertice_destino, aresta.peso)
    );
        
    if (!grafo->eh_direcionado) {
        inserirListaOrdenadoCrescente(
            grafo->lista_adjacencia[aresta.vertice_destino], 
            criarDado(aresta.vertice_origem, aresta.peso)
        );
    }
}

void imprimirGrafoVetorial(GrafoVetorial* grafo) {
    printf("TIPO: ");
    if (grafo->eh_direcionado)
        puts("GRAFO DIRECIONADO (DIGRAFO)");
    else 
        puts("GRAFO NAO DIRECIONADO");

    printf("\nVx:");
    for (int i = 0; i < grafo->quantidade_vertices; i++)
        printf(" [%d]", grafo->lista_adjacencia[i]->tamanho);
    putchar('\n');
    
    printf("Wx: ");
    No* atual;
    for (int i = 0; i < grafo->quantidade_vertices; i++) {
        atual = grafo->lista_adjacencia[i]->inicio;

        while (atual != NULL) {
            printf("[%d, %g]", atual->dado.vertice + 1, atual->dado.peso);
            atual = atual->proximo;
        }
    }
}

void destruirGrafoVetorial(GrafoVetorial* grafo) {
    for (int i = 0; i < grafo->quantidade_vertices; i++)
        destruirLista(grafo->lista_adjacencia[i]);

    free(grafo->lista_adjacencia);

    free(grafo);
}