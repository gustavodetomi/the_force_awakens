#include "header.h"

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
    - @return void
    - @param Instancia instancia[]: TODAS AS INSTANCIAS CARREGADAS
    - @param Int id_instancia: INSTANCIA QUE SERÁ USADA PARA EXECUTAR A FORCA BRUTA
*/
void busca_forca_bruta(Instancia instancias[],int id_instancia){
    Solucao solucao;
    solucao.id_instancia = id_instancia;
    solucao.n_caminhos = 0;
    int planetas[2] = {2,3};
    calcula_valor_caminho(instancias,planetas,2,0);
}

int main(){
    Instancia instancias[N_INSTANCIAS];
    inicializar_instancias(instancias);
    int num_instancias = leitura_arquivo(instancias);
   /// imprime_instancia(instancias,num_instancias);
   // imprime_instancia_log(instancias,num_instancias);
    busca_forca_bruta(instancias,0);
    return 0;
}
