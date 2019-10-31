#include "header.h"

/* 
  FORÇA BRUTA RECURSIVA -------------
*/

/*
 - FUNCAO AUXILIAR RECURSIVA PARA GERAR TODAS AS COMBINACOES POSSIVEIS DE PLANETAS SELECIONADOS
 - @return void
 - @param int n_planetas: NUMERO DE PLANETAS
 - @param int n_selecionados: NUMERO DE PLANETAS ESCOLHIDOS
 - @param int vetor_indices[]: VETOR AUXILIAR PARA SALVAR OS INDICES
 - @param int proximo: AUXILIAR PARA RECURSÃO
 - @param int k: AUXILIAR PARA RECURSÃO
 - @param Instancia intancias[]: VETOR COM TODAS AS INSTANCIAS
 - @param int id_instancia: ID DA INSTANCIA ESCOLHIDA
 - @param Caminho *caminho: CAMINHO A SER RETORNADA PARA A FUNCAO PRINCIPAL
 */
void forca_bruta_recursiva(int n_planetas, int n_selecionados, int vetor_indices[], int proximo, int k,Instancia instancias[],int id_instancia,Caminho *caminho) {
    int i;
    if (k != n_selecionados) { // "CHAMA ATÉ O INDICE SER IGUAL A K"
        for (i = proximo; i < n_planetas; i++) {
            vetor_indices[k] = i;
            forca_bruta_recursiva(n_planetas, n_selecionados, vetor_indices, i + 1, k + 1,instancias,id_instancia,caminho);
        }
    } else { // IMPRIME O VETOR CONTENDO OS INDICES

        Caminho aux_caminho = calcula_valor_caminho(instancias,vetor_indices,n_selecionados,id_instancia);
        for (i = 0; i < n_selecionados; i++){
            aux_caminho.planeta[vetor_indices[i]].selecionado = true;
            printf("%i ", vetor_indices[i] + 1); // +1 PARA NAO CONTAR COM O ZERO
        }
        // RECEBE O CAMINHO CASO ELE FOR MELHOR
        if(aux_caminho.valor_maior_aresta < caminho->valor_maior_aresta){
            copia_caminho(caminho,&aux_caminho);
        }
        printf("\n");
    }
}

/*
 - FUNCAO PRINCIPAL DA FORCA BRUTA, GERA TODAS AS COMBINACOES DE PLANETAS ESCOLHIDOS E RETORNA O MELHOR CAMINHO
 - @return void
 - @param Instancia intancias[]: VETOR COM TODAS AS INSTANCIAS
 - @param int id_instancia: ID DA INSTANCIA ESCOLHIDA
 */
Caminho forca_bruta(Instancia instancias[], int id_intancia){
   int n_planetas = instancias[id_intancia].n_planetas;
   int n_selecionados = instancias[id_intancia].n_conquistas;
   int vetor[n_selecionados];
   Caminho melhor_caminho;
   inicializa_caminho(&melhor_caminho);
   forca_bruta_recursiva(n_planetas, n_selecionados, vetor, 0, 0,instancias,id_intancia,&melhor_caminho);
   return melhor_caminho;
}


void calcula_fc_instancias(Instancia instancias[], int n_instancias,int resultado_final[]){
    for(int i=0; i<n_instancias;i++){
        printf("---------------------------\n");
        printf("SOLUCAO POR FORCA BRUTA INSTANCIA: %i\n",i);
        printf("COMBINACOES FORCA BRUTA\n");
        Caminho caminho = forca_bruta(instancias,i);
        printf("MELHOR CAMINHO (PLANETAS PARA PARAR)\n");
        imprime_caminho_formato_grafo(caminho);
        printf("---------------------------\n");
        resultado_final[i] = caminho.valor_maior_aresta;
    }
}