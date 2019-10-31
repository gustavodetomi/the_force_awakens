#include "header.h"

/*
 - REALIZA A COPIA DE UMA CAMINHO PARA OUTRO
 - @return void
 - @param Caminho *caminho_recebe: FUNCAO QUE RECEBE OS VALORES
 - @param Caminho *caminho_passa: FUNCAO QUE PASSA OS VALORES
 */
void copia_caminho(Caminho *caminho_recebe, Caminho *caminho_passa ){
    caminho_recebe->id = caminho_passa->id;
    caminho_recebe->n_planetas = caminho_passa->n_planetas;
    caminho_recebe->n_arestas = caminho_passa->n_arestas;
    caminho_recebe->id_maior_aresta = caminho_passa->id_maior_aresta;
    caminho_recebe->valor_maior_aresta = caminho_passa->valor_maior_aresta;
    for(int i=0;i<N_PLANETAS;i++){
        caminho_recebe->arestas[i].id = caminho_passa->arestas[i].id;
        caminho_recebe->arestas[i].id_planeta_inicial = caminho_passa->arestas[i].id_planeta_inicial;
        caminho_recebe->arestas[i].id_planeta_final = caminho_passa->arestas[i].id_planeta_final;
        caminho_recebe->arestas[i].distancia = caminho_passa->arestas[i].distancia;
        caminho_recebe->planeta[i].id = caminho_passa->planeta[i].id;
        caminho_recebe->planeta[i].selecionado = caminho_passa->planeta[i].selecionado;
        caminho_recebe->planeta[i].distancia = caminho_passa->planeta[i].distancia;
    }
}

/*
 - @return bool - RETORNA VERDADEIRO SE O PLANETA PERTECER 
 - @param Planeta planetas[]: TODOS OS PLANETAS QUE PERTECEM A INSTANCIA
 - @param int n_planetas: NUMERO DE PLANETAS DA INSTANCIA
 - @param int id_planeta: ID DO PLANETA A SER VERIFICADO
 */
bool esta_selecionado(Planeta planetas[],int n_planetas,int id_planeta){
    for(int i=0;i<n_planetas;i++){
        if(planetas[i].id == id_planeta){
            return true;
        }
    }
    return false;
}

/*
 - CALCULA AS DISTANCIAS DAS ARESTAS DE ACORDO COM OS PLANETAS SELECIONADOS
 - @return Caminho: RETORNA UM CAMINHO COM AS DISNTANCIAS CALCULADAS
 - @param Instancia instancias[]: TODAS AS INSTANCIAS CARREGADAS
 - @param int planetas_ids[]: PLANETAS ESCOLHIDOS DO CAMINHO
 - @param int n_planetas_selecionados: NUMERO DE PLANETAS ESCOLHIDOS
 - @param int id_instancia: ID DA INSTANCIA REFERENTE A BUSCA
 */
Caminho calcula_valor_caminho(Instancia instancias[],int planetas_ids[],int n_planetas_selecionados, int id_instancia){
    Caminho caminho;
    inicializa_caminho(&caminho);
    for(int i=0;i<n_planetas_selecionados;i++){
        caminho.planeta[i] = instancias[id_instancia].planetas[planetas_ids[i]];
        caminho.planeta[i].selecionado = true;
    }
    caminho.n_planetas = n_planetas_selecionados;
    int distancia_percorrida = 0;
    int id_planeta_inicial = 0;
    int i;
    caminho.id_maior_aresta = 0;
    caminho.valor_maior_aresta = 0;
    for(i=0;i<instancias[id_instancia].n_arestas;i++){
        distancia_percorrida += instancias[id_instancia].planetas[i].distancia;
        if(esta_selecionado(caminho.planeta,instancias[id_instancia].n_planetas,i)){
            caminho.arestas[caminho.n_arestas].id = caminho.n_arestas;
            caminho.arestas[caminho.n_arestas].id_planeta_inicial = id_planeta_inicial;
            caminho.arestas[caminho.n_arestas].id_planeta_final = planetas_ids[caminho.n_arestas];
            caminho.arestas[caminho.n_arestas].distancia = distancia_percorrida;
            if(distancia_percorrida >= caminho.valor_maior_aresta){
                caminho.id_maior_aresta = caminho.n_arestas;
                caminho.valor_maior_aresta = distancia_percorrida;
            }
            caminho.n_arestas++;
            // RESETA A DISTANCIA, PARA COMEÇAR A CONTAR PARA A PROXIMA ARESTA
            distancia_percorrida = 0;
            id_planeta_inicial = i;
        }
    }
    caminho.arestas[caminho.n_arestas].id = caminho.n_arestas;
    caminho.arestas[caminho.n_arestas].id_planeta_inicial = caminho.arestas[caminho.n_arestas].id_planeta_final;
    caminho.arestas[caminho.n_arestas].id_planeta_final = instancias[id_instancia].n_arestas-1;
    caminho.arestas[caminho.n_arestas].distancia = distancia_percorrida;
    if(distancia_percorrida >  caminho.valor_maior_aresta){
        caminho.id_maior_aresta = caminho.n_arestas;
        caminho.valor_maior_aresta = distancia_percorrida;
    }
    caminho.n_arestas++;
    return caminho;
}   