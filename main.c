#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Portuguese");
    
    int assentoCorredor[24] = {0,0,0,0,0,0, 0,0,0,0,0,0, 0,0,0,0,0,0, 0,0,0,0,0,0};
    int assentoJanela[24] = {0,0,0,0,0,0, 0,0,0,0,0,0, 0,0,0,0,0,0, 0,0,0,0,0,0};
    int opcao, numero, i, lotado = 0;
    
    //mantem o programa em loop
    while(true){
        printf("\nEscolha:\n1 - Comprar Passagem\n2 - Mostrar mapa de ocupação\n3 - Encerrar: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                opcao = 0;
                numero = 0 ;
                lotado = 0;
                
                printf("\n1 - Corredor\t2 - Janela: ");
                scanf("%d", &opcao);
                
                printf("\nNúmero da poltrona (1 à 24): ");
                scanf("%d", &numero);
                
                //primeiro verifica se o onibus esta latado
                for(i = 0; i<24; i++){
                    if(assentoCorredor[i] == 1 && assentoJanela[i] == 1){
                        lotado++;
                    }
                    else{
                        break;
                    }
                }
                
                //se a valor de lotado for menor que 24 ainda há assentos disponiveis
                if(lotado<24){
                    
                    //assentos corredor
                    if(opcao == 1){
                        //verifica se a poltrona pedida esta vazia
                        if(assentoCorredor[numero-1] == 0){
                            //marca a poltrona como ocupada
                            assentoCorredor[numero-1] = 1;
                            
                            printf("\nVenda da poltrona número %d Efetivada\n", numero);
                        }
                        else{
                            printf("\nA poltrona %d esta ocupada\n", numero);
                        }
                    }
                    
                    //assentos janela
                    else if(opcao == 2){
                        //verifica se a poltrona pedida esta vazia
                        if(assentoJanela[numero-1] == 0){
                            //marca a poltrona como ocupada
                            assentoJanela[numero-1] = 1;
                            
                            printf("\nVenda da poltrona número %d Efetivada\n", numero);
                        }
                        else{
                            printf("\nA poltrona %d esta ocupada\n", numero);
                        }
                    }
                }
                else{
                    printf("\nÔnibus lotado\n");
                }
                
                break;
                
                //mostra o mapa de assentos
            case 2:
                
                //imprime o mapa das poltronas ocupadas
                printf("\nCorredor\tjanela\n");
                
                for(i = 0; i<24; i++){
                    if(assentoCorredor[i] == 0){
                        printf("%d - Livvre\t", i+1);
                    }else{
                        printf("%d - Ocupada\t", i+1);
                    }
                    
                    //assentos da janela
                    if(assentoJanela[i] == 0){
                        printf("%d - Livvre\t", i+1);
                    }else{
                        printf("%d - Ocupada\t", i+1);
                    }
                    
                    //pula uma linha
                    printf("\n");
                }
                
                break;
                //sair do programa
            case 3:
                exit(0);
                break;
        }
    }
    
    system("PAUSE");
    return 0;
}
