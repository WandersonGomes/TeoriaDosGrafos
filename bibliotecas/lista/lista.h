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


#endif