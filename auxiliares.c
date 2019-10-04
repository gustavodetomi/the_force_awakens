#include "header.h"

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

void imprime_planeta(Planeta planeta){
    printf("Planeta id: %i\n",planeta.id);
    printf("Selecionado: %i\n",planeta.selecionado);
    printf("Distancia: %i\n",planeta.distancia);
    
}
void imprime_aresta(Aresta aresta){
    printf("Aresta id: %i\n",aresta.id);
    printf("id planeta inicial: %i\n",aresta.id_planeta_inicial);
    printf("id do planeta final: %i\n",aresta.id_planeta_final);
    printf("Distancia entre as arestas: %i\n",aresta.distancia);

}

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

void imprime_solucao(Solucao solucao){
    printf("id da instancia: %i\n",solucao.id_instancia);
    printf("id do melhor caminho: %i\n",solucao.id_melhor_caminho);
    printf("id numero de caminhos: %i\n",solucao.n_caminhos);
    for(int i = 0; i < solucao.n_caminhos; i++){
        imprime_caminho(solucao.caminhos[i]);
    }
}

void imprime__instancia(Instancia instancia){
    printf("id da instacia: %i\n",instancia.id);
    printf("numero de planetas: %i\n",instancia.n_planetas);
    printf("numero de arestas: %i\n",instancia.n_arestas);
    printf("numero de panetas a serem conquistados: %i\n",instancia.n_conquistas);
    printf("distancia total do caminho: %i\n",instancia.distancia_total);
    for(int i = 0; i < instancia.n_planetas; i++){
        imprime_planeta(instancia.planetas[i]);
    }

}

void imprime_instancia1(Instancia instancias[], int num_instancias){
    printf("%i\n",num_instancias);
    for(int i = 0; i < num_instancias; i++){
        printf("%i %i\n",instancias[i].n_planetas,instancias[i].n_conquistas);
        for(int j = 0; j < instancias[i].n_planetas+1; j++){
            printf("%i\n",instancias[i].planetas[j].distancia);
        }
    }
}

void imprime_instancia_log(Instancia instancias[], int num_instancias){
    printf("\nlog\n");
    printf("n_instancias %i\n",num_instancias);
    for(int i = 0; i < num_instancias; i++){
        printf("\n\nInstancia{ \n   id=%i \n   n_planetas=%i \n   n_conquistas=%i\n   n_arestas=%i\n   distancia_total=%i\n",instancias[i].id,instancias[i].n_planetas,instancias[i].n_conquistas,instancias[i].n_arestas,instancias[i].distancia_total);
        for(int j = 0; j < instancias[i].n_planetas+1; j++){
            printf("\n\n  Planeta{ \n      id=%i \n      distancia=%i\n     selecionado=%i\n    }",instancias[i].planetas[j].id,instancias[i].planetas[j].distancia,instancias[i].planetas[j].selecionado);
        }
    }
    printf("\n}\n");
}