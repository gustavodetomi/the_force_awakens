#include "header.h"

int main(){
    Instancia instancias[N_INSTANCIAS];
    inicializar_instancias(instancias);
    int num_instancias = leitura_arquivo(instancias);
    int res_fc[num_instancias];
    int res_guloso[num_instancias];
    
    printf("\n\n ---ARQUIVO DE ENTRADA \n\n\n");
    imprime_instancias_formato_entrada(instancias,num_instancias);

    printf("\n\n ---FORCA BRUTA \n\n\n");
    calcula_fc_instancias(instancias,num_instancias,res_fc);
    
    printf("\n\n ---ALGORTIMO GULOSO \n\n\n");
    calcula_alg_guloso_instancias(instancias,num_instancias,res_guloso);
    
    printf("\n\n ---RESULTADOS FINAIS \n\n\n");
    printf("FORCA BRUTA | GULOSO | PROGRAMACAO DINAMICA\n");
    for(int i=0;i<num_instancias;i++){
        if(res_fc[i] >= 10 || res_guloso[i] >= 10){
            printf("     %i     |   %i   | ---------------------\n",res_fc[i],res_guloso[i]);
        } else {
            printf("     %i      |    %i   | ---------------------\n",res_fc[i],res_guloso[i]);
        }
    }
    return 0;
}
