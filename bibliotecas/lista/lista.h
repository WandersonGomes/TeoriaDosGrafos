#ifndef __LISTA__
#define __LISTA__

typedef struct {
    int vertice;
    double peso;
} Dado;

Dado criarDado(int vertice, double peso);

typedef struct no {
    Dado dado;
    struct no* proximo;
} No;

No* criarNo(Dado dado);
void imprimirNo(No* no);

typedef struct {
    int tamanho;
    No* inicio;
} Lista;

Lista* criarLista();
void inserirListaOrdenadoCrescente(Lista* lista, Dado dado);
void imprimirLista(Lista* lista);
void destruirLista(Lista* lista);

#endif