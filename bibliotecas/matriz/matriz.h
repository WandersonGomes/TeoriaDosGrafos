#ifndef __MATRIZ__
#define __MATRIZ__

int** criarMatrizIntDinamica(int quantidade_linhas, int quantidade_colunas);
void destruirMatrizIntDinamica(int** matriz, int quantidade_linhas);
void imprimirMatrizIntDinamica(int** matriz, int quantidade_linhas, int quantidade_colunas);

double** criarMatrizDoubleDinamica(int quantidade_linhas, int quantidade_colunas);
void destruirMatrizDoubleDinamica(double** matriz, int quantidade_linhas);
void imprimirMatrizDoubleDinamica(double** matriz, int quantidade_linhas int quantidade_colunas);

#endif