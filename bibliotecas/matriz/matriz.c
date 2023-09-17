#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void iniciarlizarMatrizIntDinamica(int** matriz, int quantidade_linhas, int quantidade_colunas) {
    for (int i = 0; i < quantidade_linhas; i++)
        for (int j = 0; j < quantidade_colunas; j++)
            matriz[i][j] = 0;
}

int** criarMatrizIntDinamica(int quantidade_linhas, int quantidade_colunas) {
    int** matriz = (int**) malloc(sizeof(int*) * quantidade_linhas);

    for (int i = 0; i < quantidade_linhas; i++)
        matriz[i] = (int*) malloc(sizeof(int) * quantidade_colunas);

    iniciarlizarMatrizIntDinamica(matriz, quantidade_linhas, quantidade_colunas);

    return matriz;
}

void destruirMatrizIntDinamica(int** matriz, int quantidade_linhas) {
    for (int i = 0; i < quantidade_linhas; i++)
        free(matriz[i]);
    
    free(matriz);
}

void imprimirMatrizIntDinamica(int** matriz, int quantidade_linhas, int quantidade_colunas) {
    for (int i = 0; i < quantidade_linhas; i++) {
        for (int j = 0; j < quantidade_colunas; j++)
            printf("%d ", matriz[i][j]);

        putchar('\n');
    }
}

void iniciarlizarMatrizDoubleDinamica(double** matriz, int quantidade_linhas, int quantidade_colunas) {
    for (int i = 0; i < quantidade_linhas; i++)
        for (int j = 0; j < quantidade_colunas; j++)
            matriz[i][j] = 0.00;
}

double** criarMatrizDoubleDinamica(int quantidade_linhas, int quantidade_colunas) {
    double** matriz = (double**) malloc(sizeof(double*) * quantidade_linhas);

    for (int i = 0; i < quantidade_linhas; i++)
        matriz[i] = (double*) malloc(sizeof(double) * quantidade_colunas);

    iniciarlizarMatrizDoubleDinamica(matriz, quantidade_linhas, quantidade_colunas);

    return matriz;
}

void destruirMatrizDoubleDinamica(double** matriz, int quantidade_linhas) {
    for (int i = 0; i < quantidade_linhas; i++)
        free(matriz[i]);
    
    free(matriz);
}

void imprimirMatrizDoubleDinamica(double** matriz, int quantidade_linhas, int quantidade_colunas) {
    for (int i = 0; i < quantidade_linhas; i++) {
        for (int j = 0; j < quantidade_colunas; j++)
            printf("%g ", matriz[i][j]);

        putchar('\n');
    }
}