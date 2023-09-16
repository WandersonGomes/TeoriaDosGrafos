#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Dado criarDado(int vertice, double peso) {
    Dado dado;

    dado.vertice = vertice;
    dado.peso = peso;

    return dado;
}

No* criarNo(Dado dado) {
    No* no = (No*) malloc(sizeof(No));

    if (no != NULL) {
        no->dado = dado;
        no->proximo = NULL;
    }

    return no;
}

void imprimirNo(No* no) {
    printf("[%d | %g]->", no->dado.vertice, no->dado.peso);
}

Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));

    if (lista != NULL) {
        lista->tamanho = 0;
        lista->inicio = NULL;
    }

    return lista;
}

void inserirListaOrdenadoCrescente(Lista* lista, Dado dado) {
    No* novo_no = criarNo(dado);

    if (lista->inicio == NULL) {
        lista->inicio = novo_no;
    } else {
        if (lista->tamanho == 1) {
            if (lista->inicio->dado.vertice >= dado.vertice)
                lista->inicio->proximo = novo_no;
            else {
                novo_no->proximo = lista->inicio;
                lista->inicio = novo_no;
            }
        } else {
            No* no_anterior = lista->inicio;
            No* no_atual = lista->inicio;

            while (no_atual->dado.vertice < no_atual->dado.vertice) {
                no_anterior = no_atual;
                no_atual = no_atual->proximo;
                
                if (no_atual == NULL)
                    break;
            }

            no_anterior->proximo = novo_no;
            novo_no->proximo = no_atual;
        }
    }

    lista->tamanho++;
}

void imprimirLista(Lista* lista) {
    for (No* no_atual = lista->inicio; no_atual != NULL; no_atual = no_atual->proximo)
        imprimirNo(no_atual);
    putchar('\n');
}

void destruirLista(Lista* lista) {
    No* no_atual = lista->inicio;
    No* proximo;

    while (no_atual != NULL) {
        proximo = no_atual->proximo;
        free(no_atual);
        no_atual = proximo;
    }

    free(lista);
}