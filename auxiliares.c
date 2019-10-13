#include "header.h"

/*
 - INICIALIZA OS VALORES DAS INSTANCIAS
 - @return void
 - @param Instancia instancias[]: VETOR CONTENDO AS INSTANCIAS
 */
void inicializar_instancias(Instancia instancias[]){
    for(int i = 0; i < N_INSTANCIAS; i++){
        instancias[i].id = -1;
        instancias[i].n_conquistas = -1;
        instancias[i].n_arestas = -1;
        instancias[i].n_planetas = 0;
        instancias[i].distancia_total = 0;
        for (int j = 0; j < N_PLANETAS; j++){
            instancias[i].planetas[j].distancia = -1;
            instancias[i].planetas[j].selecionado = 0;
            instancias[i].planetas[j].id = -1;
        }
    }
}

/*
 - IMPRIME UM REGISTRO DO TIPO Planeta
 - @return void
 - @param Planeta planeta: REGISTRO DO TIPO PLANETA
 */
void imprime_planeta(Planeta planeta){
    printf("Planeta id: %i\n",planeta.id);
    printf("Selecionado: %i\n",planeta.selecionado);
    printf("Distancia: %i\n",planeta.distancia);
}

/*
 - IMPRIME UM REGISTRO DO TIPO Aresta
 - @return void
 - @param Aresta aresta: REGISTRO DO TIPO Aresta
 */
void imprime_aresta(Aresta aresta){
    printf("Aresta id: %i\n",aresta.id);
    printf("id planeta inicial: %i\n",aresta.id_planeta_inicial);
    printf("id do planeta final: %i\n",aresta.id_planeta_final);
    printf("Distancia entre as arestas: %i\n",aresta.distancia);
}

/*
 - IMPRIME UM REGISTRO DO TIPO Caminho
 - @return void
 - @param Caminho caminho: REGISTRO DO TIPO Caminho
 */
void imprime_caminho(Caminho caminho){
    printf("id=%i\n",caminho.id);
    for(int i = 0; i < caminho.n_arestas; i++){
        imprime_aresta(caminho.arestas[i]);
    }
    for(int i = 0; i < caminho.n_planetas; i++){
        imprime_planeta(caminho.planeta[i]);
    }
    printf("n_planetas=%i\n",caminho.n_planetas);
    printf("n_arestas=%i\n",caminho.n_arestas);
    printf("float=%f\n",caminho.fitnes);
}

/*
 - IMPRIME UM REGISTRO DO TIPO Solucao
 - @return void
 - @param Solucao solucao: REGISTRO DO TIPO Solucao
 */
void imprime_solucao(Solucao solucao){
    printf("id da instancia: %i\n",solucao.id_instancia);
    printf("id do melhor caminho: %i\n",solucao.id_melhor_caminho);
    printf("id numero de caminhos: %i\n",solucao.n_caminhos);
    for(int i = 0; i < solucao.n_caminhos; i++){
        imprime_caminho(solucao.caminhos[i]);
    }
}

/*
 - IMPRIME UM REGISTRO DO TIPO Instancia
 - @return void
 - @param Instancia instancia: REGISTRO DO TIPO Instancia
 */
void imprime_instancia(Instancia instancia){
    printf("id da instacia: %i\n",instancia.id);
    printf("numero de planetas: %i\n",instancia.n_planetas);
    printf("numero de arestas: %i\n",instancia.n_arestas);
    printf("numero de panetas a serem conquistados: %i\n",instancia.n_conquistas);
    printf("distancia total do caminho: %i\n",instancia.distancia_total);
    for(int i = 0; i < instancia.n_planetas; i++){
        imprime_planeta(instancia.planetas[i]);
    }
}

/*
 - IMPRIME AS INSTANCIAS CARREGADAS NO FORMATO DA ENTRADA PELO ARQUIVO
 - @return void
 - @param Instancia instancias[]: VETOR DE REGISTROS DO TIPO Instancia
 - @param int num_instancias: NUMERO DE INSTANCIAS PRESENTES DO VETOR instancias[]
 */
void imprime_instancias_formato_entrada(Instancia instancias[], int num_instancias){
    printf("%i\n",num_instancias);
    for(int i = 0; i < num_instancias; i++){
        printf("%i %i\n",instancias[i].n_planetas,instancias[i].n_conquistas);
        for(int j = 0; j < instancias[i].n_planetas+1; j++){
            printf("%i\n",instancias[i].planetas[j].distancia);
        }
    }
}