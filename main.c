#include <stdio.h>
#include <string.h>
#include "./bibliotecas/grafo/grafo_adjacencia.h"
#include "./bibliotecas/grafo/grafo_incidencia.h"
#include "./bibliotecas/grafo/grafo_lista.h"

#include "./bibliotecas/grafo/grafo_peso.h"

#define ERROR -1
#define SUCESSO 1

#define DIRECIONADO 1
#define NAO_DIRECIONADO 0

void apresentarAjuda() {
    puts("Autores: \
    Adriano Pereira da Silva Junior,\ 
    Helder Oliveira de Andrade,\
     Isaac de Sa da Silva, \
    Wanderson Gomes da Costa.\n");
    
    puts("grafo.o read <arquivo de entrada> show [TIPO DE IMPLEMENTACAO DO GRAFO] [DIRECIONADO - OPCIONAL]\n");
    puts("[TIPO DE IMPLEMENTACAO DO GRAFO]:");
    puts("\t-ma: implementa o grafo como uma matriz de adjacencia\n");
    puts("\n[DIRECIONADO = OPCIONAL]:");
    puts("\t-d: considera o grafo como direcionado.");
}

int verificarArgumentosLinhaComando(int quantidade_argumentos, const char** argumentos) {
    if (quantidade_argumentos == 2) 
        return (strcmp(argumentos[1], "help") != 0) ? ERROR : SUCESSO;

    //programa[0] read[1] <input file>[2] show[3] [tipo de implementacao][4] [direcionado - opcional][6]
    if (quantidade_argumentos > 6) return ERROR;
    
    if (strcmp(argumentos[1], "read") != 0) return ERROR;
    
    if (strcmp(argumentos[3], "show") != 0) return ERROR;

    return SUCESSO;
}

void implementarGrafoMatrizAdjacencia(FILE* arquivo, int direcionado) {
    int quantidade_vertices;

    fscanf(arquivo, "%d", &quantidade_vertices);
    
    if (quantidade_vertices < 1) {
    
        puts("ERROR: quantidade vertices invalida!");
    
    } else {
    
        GrafoMatrizAdjacencia* grafoMatrizAdjacencia = criarGrafoMatrizAdjacencia(quantidade_vertices, direcionado);
                    
        Aresta aresta;
        while (fscanf(arquivo, "%d %d %lf", &aresta.vertice_origem, &aresta.vertice_destino, &aresta.peso) != EOF) {
            aresta.vertice_origem--;
            aresta.vertice_destino--;

            adicionarArestaGrafoMatrizAdjacencia(grafoMatrizAdjacencia, aresta);                
        }
                        
        imprimirGrafoMatrizAdjacencia(grafoMatrizAdjacencia);

        destruirGrafoMatrizAdjacencia(grafoMatrizAdjacencia);
    
    }
}

void implementarGrafoMatrizIncidencia(FILE* arquivo, int direcionado) {
    int quantidade_vertices;

    fscanf(arquivo, "%d", &quantidade_vertices);

    if (quantidade_vertices < 1) {
        
        puts("ERROR: quantidade vertices invalida!");

    } else {
        Aresta aresta;
        int quantidade_arestas = 0;
    
        while (fscanf(arquivo, "%d %d %lf", &aresta.vertice_origem, &aresta.vertice_destino, &aresta.peso) != EOF)
            quantidade_arestas++;
        
        fseek(arquivo, 0, SEEK_SET);
        fscanf(arquivo, "%*d");

        GrafoMatrizIncidencia* grafoMatrizIncidencia = criarGrafoMatrizIncidencia(quantidade_vertices, quantidade_arestas, direcionado);
        int numero = 0;

        while (fscanf(arquivo, "%d %d %lf", &aresta.vertice_origem, &aresta.vertice_destino, &aresta.peso) != EOF) {
            aresta.vertice_origem--;
            aresta.vertice_destino--;

            adicionarArestaGrafoMatrizIncidencia(grafoMatrizIncidencia, aresta, numero++); 
        }
                        
        imprimirGrafoMatrizIncidencia(grafoMatrizIncidencia);

        destruirGrafoMatrizIncidencia(grafoMatrizIncidencia);

    }
}

void implementarGrafoListaAdjacencia(FILE* arquivo, int direcionado) {
    int quantidade_vertices;

    fscanf(arquivo, "%d", &quantidade_vertices);
    
    if (quantidade_vertices < 1) {
    
        puts("ERROR: quantidade vertices invalida!");
    
    } else {
    
        GrafoListaAdjacencia* grafoListaAdjacencia = criarGrafoListaAdjacencia(quantidade_vertices, direcionado);
                    
        Aresta aresta;
        while (fscanf(arquivo, "%d %d %lf", &aresta.vertice_origem, &aresta.vertice_destino, &aresta.peso) != EOF)
            adicionarArestaGrafoListaAdjacencia(grafoListaAdjacencia, aresta);                
                        
        imprimirGrafoListaAdjacencia(grafoListaAdjacencia);

        destruirGrafoListaAdjacencia(grafoListaAdjacencia);
    }
}

int main(int quantidade_argumentos, const char** argumentos) {
    if (verificarArgumentosLinhaComando(quantidade_argumentos, argumentos) == SUCESSO) {
        if (quantidade_argumentos == 2) {
            apresentarAjuda();
            return 0;
        }

        FILE* arquivo = fopen(argumentos[2], "r");

        if (arquivo != NULL) {            
            int opcao_direcionado;

            if ((quantidade_argumentos > 5) && (!strcmp("-d", argumentos[5]))) 
                opcao_direcionado = DIRECIONADO;
            else
                opcao_direcionado = NAO_DIRECIONADO;

            if (!strcmp(argumentos[4], "-ma"))
                implementarGrafoMatrizAdjacencia(arquivo, opcao_direcionado);
            else if (!strcmp(argumentos[4], "-mi"))
                implementarGrafoMatrizIncidencia(arquivo, opcao_direcionado);
            else if (!strcmp(argumentos[4], "-la"))
                implementarGrafoListaAdjacencia(arquivo, opcao_direcionado);

            fclose(arquivo);
        } else {
            puts("ERROR: problema ao abrir o arquivo para leitura.");
        }
    } else {
        apresentarAjuda();
    }

    return 0;
}

