#ifndef __HEADER
#define __HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define N_PLANETAS 502
#define N_INSTANCIAS 100 
#define N_CONQUISTAS 250

// STRUCTS ENTRADA DE DADOS
typedef struct Planeta{
    int id;
    bool selecionado;
    int distancia;
}Planeta;

typedef struct Instancia{
    int id;
    int n_planetas;
    int n_arestas;
    int n_conquistas;
    int distancia_total;
    Planeta planetas[N_PLANETAS];
}Instancia;

// STRUCTS AUXLIARES PARA OS ALGORITMOS
typedef struct Aresta{
    int id;
    int id_planeta_inicial;
    int id_planeta_final;
    int distancia;
}Aresta;

typedef struct Caminho{
    int id;
    Aresta arestas[N_PLANETAS];
    Planeta planeta[N_PLANETAS];
    int n_planetas;
    int n_arestas;
    float fitnes; // O QUANTO O CAMINHO É BOM, QUANTO MENOR MELHORplanetaplanetaplaneta
}Caminho;

typedef struct Solucao{
    int id_instancia;
    int id_melhor_caminho;
    int n_caminhos;
    Caminho caminhos[N_CONQUISTAS];
}Solucao;

// LENDO O ARQUIVO CONTENDO AS INFORMACOES DE ENTRADA
int leitura_arquivo(Instancia instancias[]);

// INCIALIZA OS VETORES CONTENDO AS INSTANICIAS E OS PLANETAS
void inicializar_instancias(Instancia instancias[]);

// FUNCAO AUXILIAR PARA IMPRIMIR A ENTRADA DO ARQUIVO
void imprime_instancia(Instancia instancias[], int num_instancias);

// FUNÇÃO AUXILIAR PARA IMPRIMIR NO FORMATO DA STRUCT
void imprime_instancia_log(Instancia instancias[], int num_instancias);

#endif //__HEADER
