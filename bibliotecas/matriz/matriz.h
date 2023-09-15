#ifndef __MATRIZ__
#define __MATRIZ__

double** criarMatrizDinamica(int quantidade_linhas, int quantidade_colunas);
void inicializarMatrizDinamica(double** matriz, int quantidade_linhas, int quantidade_colunas);
void imprimirMatrizDinamica(double** matriz, int quantidade_linhas, int quantidade_colunas);
void destruirMatrizDinamica(double** matriz, int quantidade_linhas);

#endif