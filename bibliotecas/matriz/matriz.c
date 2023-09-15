#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void inicializarMatrizDinamica(double** matriz, int quantidade_linhas, int quantidade_colunas) {
    for (int i = 0; i < quantidade_linhas; i++)
        for (int j = 0; j < quantidade_colunas; j++)
            matriz[i][j] = 0.00;
}

double** criarMatrizDinamica(int quantidade_linhas, int quantidade_colunas) {
    double** matriz = (double**) malloc(sizeof(double*) * quantidade_linhas);
    int i, j;

    for (i = 0; i < quantidade_linhas; i++)
        matriz[i] = (double*) malloc(sizeof(double) * quantidade_colunas);

    inicializarMatrizDinamica(matriz, quantidade_linhas, quantidade_colunas);

    return matriz;
}

void imprimirMatrizDinamica(double** matriz, int quantidade_linhas, int quantidade_colunas) {
    for (int i = 0; i < quantidade_linhas; i++) {
        for (int j = 0; j < quantidade_colunas; j++)
            (j != 0) ? printf(" %g", matriz[i][j]) : printf("%g", matriz[i][j]);
        
        putchar('\n');
    }
}

void destruirMatrizDinamica(double** matriz, int quantidade_linhas) {
    for (int i = 0; i < quantidade_linhas; i++)
        free(matriz[i]);
    
    free(matriz);
}