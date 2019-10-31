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

/*
   MODULARIZACAO DOS REGISTROS DE ENTRADA PELO ARQUIVO DE TEXTO
*/

typedef struct Planeta{
    int id;
    bool selecionado;
    int distancia;
    float fitnes; // USADO NA SOLUCAO GULOSA
}Planeta;

typedef struct Instancia{
    int id;
    int n_planetas;
    int n_arestas;
    int n_conquistas;
    int distancia_total;
    Planeta planetas[N_PLANETAS];
}Instancia;

/*
   MODULARIZACAO DOS REGISTROS USADOS NA SOLUCAO
*/

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
    int id_maior_aresta; 
    int valor_maior_aresta; // PODE SER RECUPERADO TAMBEM PELO ID DA ARESTA
}Caminho;

typedef struct Solucao{
    int id_instancia;
    int id_melhor_caminho;
    int n_caminhos;
    Caminho caminhos[N_CONQUISTAS];
}Solucao;

/*
--- FUNCOES OPERAÇÕES COM ARQUIVOS
    leitura_arquivo.c
*/

int leitura_arquivo(Instancia instancias[]);

/*
--- FUNCOES AUXILIARES PARA PARA LOG
    auxiliares.C
*/

void inicializar_instancias(Instancia instancias[]);

void inicializar_instancias(Instancia instancias[]);

void inicializa_planeta(Planeta *planeta);

void inicializa_aresta(Aresta *aresta);

void inicializa_caminho(Caminho *caminho);

void imprime_caminho_formato_grafo(Caminho caminho);

void imprime_aresta(Aresta aresta);

void imprime_caminho(Caminho caminho);

void imprime_solucao(Solucao solucao);

void imprime_instancia(Instancia instancia);

void imprime_instancias_formato_entrada(Instancia instancias[], int num_instancias);

/*
--- FUNCOES USADAS PARA CALCULAR O VALOR DO CAMINHO
    DE ACORDO COM OS PLANETAS SELECIONADOS
    - leitura_arquivo.c
*/

void copia_caminho(Caminho *caminho_recebe, Caminho *caminho_passa );

bool esta_selecionado(Planeta planetas[],int n_planetas,int id_planeta);

Caminho calcula_valor_caminho(Instancia instancias[],int planetas_ids[],int n_planetas_selecionados, int id_instancia);

/*
--- FUNCOES USADAS NO ALGORITMO DE FORCA BRUTA
    - forca_bruta.c
*/

Caminho forca_bruta(Instancia instancias[], int id_intancia);

void forca_bruta_recursiva(int n_planetas, int n_selecionados, int vetor_indices[], int proximo, int k,Instancia instancias[],int id_instancia,Caminho *caminho);

void calcula_fc_instancias(Instancia instancias[], int n_instancias,int resultado_final[]);
/*
--- FUNCOES USADAS NO ALGORITMO GULOSO
    - algorimo_guloso.c
*/

void ordena_planetas(Planeta Ordena[], int tamanho);

Caminho algoritmo_guloso(Instancia instancias[], int id_instancia);

void calcula_alg_guloso_instancias(Instancia instancias[], int n_instancias, int resultado_final[]);

#endif //__HEADER
