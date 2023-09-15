#ifndef __LISTA__
#define __LISTA__

typedef struct no {
    int dado;
    struct no* proximo;
} No;

typedef struct {
    int tamanho;
    No* inicio;
} Lista;

Lista* criarLista();
void inserir(Lista* lista, int dado);
void imprimirLista(Lista* lista);
void destruirLista(Lista* lista);

#endif