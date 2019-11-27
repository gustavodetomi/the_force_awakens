#include "header.h"

/*
 - ORDENA UM ARRAY DO TIPO PLANETA EM ORDEM CRESCENTE   
 - @return void
 - @param Planeta planeta[]: VETOR QUE CONTEM OS PLANETAS a serem ordenados
 - @param int tamanho: NUMERO DE INSTANCIAS NOS ARRAY PLANETAS
 */
void ordena_planetas(Planeta Ordena[], int tamanho){
   int i, j;
   struct Planeta aux;
   
   for (j=tamanho-1; j>0; j--){
        for (i=0; i<j; i++){
            if (Ordena[i].fitnes > Ordena[i+1].fitnes){                            
                aux = Ordena[i];
                Ordena[i] = Ordena[i+1];
                Ordena[i+1] = aux;             
            }
        }
    }
}


/*
 - REALIZA A APLICACAO DO ALGORITMO GULOSO
   O ALGORITMO CALCULA A MEDIA DAS DISTANCIAS EM RELACAO AO NUMERO DE ARESTAS,
   LOGO APOS SUBTRAI ESSA DISTANCIA PELO DE CADA ARESTA, LOGO APOS ESSE RESULTADO
   OBTIDO E ORDENADO E POR FIM O ALGORITMO SELECIONA OS MENORES VALORES
 - @return Caminho caminho - RETORNA UMA STRUCT DO TIPO CAMINHO
 - @param Instancia instancias[]: VETOR DE REGISTROS DO TIPO Instancia
 - @param int id_instancia: ID DA INSTANCIA QUE O ALGORITMO SERA APLICADO
 */
Caminho algoritmo_guloso(Instancia instancias[], int id_instancia){
    float soma_distancias = 0.0f;
    // CALCULA A MEDIA DAS DISTANCIA EM RELACAO AO NUMERO DE ARESTAS
    for(int i=0;i<instancias[id_instancia].n_arestas;i++){
        soma_distancias += instancias[id_instancia].planetas[i].distancia;
    }
    float media = soma_distancias / instancias[id_instancia].n_planetas;
    printf("Media = %f\n",media);

    int planetas_escolhidos[instancias[id_instancia].n_conquistas];
    int solucao[instancias[id_instancia].n_arestas];
    Planeta planetas[instancias[id_instancia].n_arestas];

    // CALCULA O FINESS DE CADA ARESTA (MEDIA - DINSTANCIA)
    for(int i=0; i<instancias[id_instancia].n_arestas;i++ ){
        planetas[i].id = instancias[id_instancia].planetas[i].id;
        planetas[i].distancia = instancias[id_instancia].planetas[i].distancia;
        planetas[i].fitnes = media - instancias[id_instancia].planetas[i].distancia;
    }

    // ORDENA OS RESULTADOS (QUANTO MENOR MELHOR)
    ordena_planetas(planetas,instancias[id_instancia].n_arestas);

    int cont = 0;
    int cont2 = 0;
    // PEGA OS MENORES VALORES
    while(cont2 != instancias[id_instancia].n_conquistas){
        if(planetas[cont].id != 0){ // NÃO PODE SELECIONAR O "PLANETA" INICIAL
            solucao[cont2] = planetas[cont].id-1;
            cont2++;
        }
        cont++;
    }

    Caminho caminho = calcula_valor_caminho(instancias,solucao,instancias[id_instancia].n_conquistas,id_instancia);
    return caminho;
}

/*
 - APLICA O ALGORITMO GULOSO EM TODAS AS INTANCIAS PASSADAS POR REFERENCIA, E RETORNA O RESULTADO
   ATRAVES DO PARAMETRO 'resultado_final[]'
 - @return void
 - @param Instancia instancias[]: VETOR DE REGISTROS DO TIPO Instancia
 - @param int num_instancias: NUMERO DE INSTANCIAS PRESENTES DO VETOR instancias[]
 - @param int resultado_final[]: PARAMETRO DE SAIDA, QUE CONTEM OS VALORES FINAIS
   DAS MAIORES ARESTAS DE CADA PROBLEMA
 */
void calcula_alg_guloso_instancias(Instancia instancias[], int n_instancias,int resultado_final[]){
    for(int i=0; i<n_instancias;i++){
        printf("---------------------------\n");
        printf("SOLUCAO POR ALGORITMO GULOSO INSTANCIA: %i\n",i);
        Caminho caminho = algoritmo_guloso(instancias,i);
        printf("MELHOR CAMINHO (PLANETAS PARA PARAR)\n");
        imprime_caminho_formato_grafo(caminho);
        printf("---------------------------\n");
        resultado_final[i] = caminho.valor_maior_aresta;
    }
}