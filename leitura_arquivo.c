#include "header.h"

/*
 - FUNCAO LE O ARQUIVO DE ENTRADA E CARREGA AS INFORMACOES DE ENTRADA
   LINHA 1 - PRIMEIRO INTEIRO = NUMERO DE INSTANCIAS
   LINHA 2 - PRIMEIRO INTEIRO = NUMERO DE PLANETAS
   LINHA 2 - SEGUNDO INTEIRO = NUMERO DE CONQUISTAS
   LINHAS * - PESO DA DISTANCIA DA ARESTA DOS PLANETAS
   REPETE ATE ACABAR AS IN
 - @return int - RETORNA O NUMERO DE INSTANCIAS
 - @param Instancia[]: VETOR A SER CARREGADO COM A ENTRADA
 */
int leitura_arquivo(Instancia instancias[]){
    int num_instancias = -1;
    //LEITURA ATRAVÉS DO ARQUIVO
    FILE* arquivo = fopen("entrada.txt","r");
    if (arquivo == NULL){
        printf("ARQUIVO NAO ENCONTRADO\n");
        return num_instancias;
    }
    fscanf(arquivo,"%i",&num_instancias);
    for(int i=0;i<num_instancias;i++){
        fscanf(arquivo,"%i %i",&instancias[i].n_planetas,&instancias[i].n_conquistas);
        instancias[i].id = i;
        instancias[i].n_arestas = instancias[i].n_planetas+1;
        for(int j=0;j<instancias[i].n_arestas;j++){
            fscanf(arquivo,"%i",&instancias[i].planetas[j].distancia);
            instancias[i].planetas[j].id = j;
            instancias[i].distancia_total += instancias[i].planetas[j].distancia;
        }
    }
    return num_instancias;
}

