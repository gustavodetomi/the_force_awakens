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
    float fitnes; // O QUANTO O CAMINHO É BOM, QUANTO MENOR MELHOR
}Caminho;

typedef struct Solucao{
    int id_instancia;
    int id_melhor_caminho;
    int n_caminhos;
    Caminho caminhos[N_CONQUISTAS];
}Solucao;

/*
    FUNCOES leitura_arquivo.c
*/

int leitura_arquivo(Instancia instancias[]);

/*
   FUNCOES auxiliares.C
*/

void inicializar_instancias(Instancia instancias[]);

/*
--- FUNCOES AUXILIARES PARA PARA LOG
*/

void imprime_planeta(Planeta planeta);

void imprime_aresta(Aresta aresta);

void imprime_caminho(Caminho caminho);

void imprime_solucao(Solucao solucao);

void imprime_instancia(Instancia instancias);

void imprime_instancias_formato_entrada(Instancia instancias[], int num_instancias);

#endif //__HEADER
