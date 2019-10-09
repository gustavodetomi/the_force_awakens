#include "header.h"

/* 
    FUNCOES NAO TERMINADAS, PARA AVALIAR O MELHOR CAMINHO
*/

/*
 - @return bool - RETORNA VERDADEIRO SE O PLANETA PERTECER 
 - @param Planeta planetas[]: TODOS OS PLANETAS QUE PERTECEM A INSTANCIA
 - @param int n_planetas: NUMERO DE PLANETAS DA INSTANCIA
 - @param int id_planeta: ID DO PLANETA A SER VERIFICADO
 */
bool esta_selecionado(Planeta planetas[],int n_planetas,int id_planeta){
    for(int i=0;i<n_planetas+1;i++){
        printf("\nid=%i busca=%i",planetas[i].id,id_planeta);
        if(planetas[i].id == id_planeta){
            return true;
        }
    }
    return false;
}

/*
 - @return void
 - @param Instancia instancias[]: TODAS AS INSTANCIAS CARREGADAS
 - @param int planetas_ids[]: PLANETAS ESCOLHIDOS DO CAMINHO
 - @param int n_planetas_selecionados: NUMERO DE PLANETAS ESCOLHIDOS
 - @param int id_instancia: ID DA INSTANCIA REFERENTE A BUSCA
 */
void calcula_valor_caminho(Instancia instancias[],int planetas_ids[],int n_planetas_selecionados, int id_instancia){
    Caminho caminho;
    Aresta aresta_aux;
    float media; // DISTANCIA TOTAL DIVIDO PELO NUMERO DE CONEXOES A SEREM FEITAS
    media = ((float)instancias[id_instancia].distancia_total / (float)(instancias[id_instancia].n_conquistas+1));
    //printf("\ndistancia=%i n_conquistas+1=%i media =%f\n",instancias[id_instancia].distancia_total,instancias[id_instancia].n_conquistas+1,media); 
    for(int i=0;i<n_planetas_selecionados;i++){
        caminho.planeta[i] = instancias[id_instancia].planetas[planetas_ids[i]];
    }

    caminho.n_planetas = n_planetas_selecionados;
    int distancia_percorrida = 0;
    for(int i=0;i<instancias[id_instancia].n_arestas;i++){
        if(esta_selecionado(caminho.planeta,instancias[id_instancia].n_planetas,i)){
            printf("\nPlaneta_selecionado=%i\n",i);
        }
    }
    return;
}   

/* 
    BUSCA RECURSIVA -------------
*/


/*
 - FUNCAO AUXILIAR RECURSIVA PARA GERAR TODAS AS COMBINACOES POSSIVEIS DE PLANETAS SELECIONADOS
 - @return void
 - @param int n_planetas: NUMERO DE PLANETAS
 - @param int n_selecionados: NUMERO DE PLANETAS ESCOLHIDOS
 - @param int vetor_indices[]: VETOR AUXILIAR PARA SALVAR OS INDICES
 - @param int proximo: AUXILIAR PARA RECURSÃO
 - @param int k: AUXILIAR PARA RECURSÃO
 */
void forca_bruta_recursiva(int n_planetas, int n_selecionados, int vetor_indices[], int proximo, int k) {
    int i;
    if (k != n_selecionados) { // "CHAMA ATÉ O INDICE SER IGUAL A K"
        for (i = proximo; i < n_planetas; i++) {
            vetor_indices[k] = i;
            forca_bruta_recursiva(n_planetas, n_selecionados, vetor_indices, i + 1, k + 1);
        }
    } else { // IMPRIME O VETOR CONTENDO OS INDICES
        for (i = 0; i < n_selecionados; i++){
            printf("%i ", vetor_indices[i] + 1); // +1 PARA NAO CONTAR COM O ZERO
        }
        printf("\n");
    }
}


/*
 - FUNCAO PRINCIPAL DA FORCA BRUTA, GERA TODAS AS COMBINACOES DE PLANETAS ESCOLHIDOS
 - @return void
 - @param int n_planetas: NUMERO DE PLANETAS
 - @param int n_selecionados: NUMERO DE PLANETAS ESCOLHIDOS
 */
void forca_bruta(int n_planetas, int n_selecionados){
   int vetor[n_selecionados];
   forca_bruta_recursiva(n_planetas, n_selecionados, vetor, 0, 0);
}


int main(){
    Instancia instancias[N_INSTANCIAS];
    inicializar_instancias(instancias);
    int num_instancias = leitura_arquivo(instancias);
    imprime_instancia(instancias,num_instancias);
    imprime_instancia_log(instancias,num_instancias);
    forca_bruta(3,2);
    return 0;
}
