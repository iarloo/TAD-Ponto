#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"
#define MAX_PONTOS 10

int main()
{
    ///Variaveis Principais
    int funcaoDesejada = 1;
    Ponto *pontos[MAX_PONTOS]; // vetor pra guardar os pontos
    int numPontos = 0; //indicador de quantos pontos eu ja existem
    int indiceValido = 0; //Flag para dizer se o indice fornecido foi digitado corretamente.


    while(funcaoDesejada < 6 && funcaoDesejada > 0){ //Definir limite de opções
        printf("Numero Máximo de pontos : %d\n", MAX_PONTOS - numPontos);
        printf("1 - Criar Ponto\n");
        printf("2 - Libera Ponto\n");
        printf("3 - Acessa Ponto\n");
        printf("4 - Atribuir Ponto\n");
        printf("5 - Distancia de dois pontos\n");
        printf("6 - Sair\n");

        printf("Escolha uma função: ");
        //Recolhe a função desejada do usuario;
        scanf("%d", &funcaoDesejada);

        switch(funcaoDesejada){
            case 1:
                //limpaTela();
                float x,y;
                printf("\n1 - Criar Ponto\n");

                if(numPontos < MAX_PONTOS){

                    printf("Digite as coordenadas de seu ponto\n");
                    printf("Digite o valor x :"); scanf("%f", &x);
                    printf("Digite o valor y :"); scanf("%f", &y);

                    pontos[numPontos] = Ponto_cria(x,y);
                    printf("Ponto %d criado: (%.1f, %.1f)\n", numPontos + 1, x, y);
                    numPontos++;
                }else{
                    printf("Numero máximo de pontos atingido, será criados novos pontos uma vez que algum ponto pré existente é liberado.\n");
                }
                break;

            case 2:
                indiceValido = 0;
                while(indiceValido == 0) { //Programa entra em loop se o indice foi digitado incorretamente.
                    if (numPontos > 0) {
                        int indice;
                        printf("Digite o indice do ponto a ser liberado (0 a %d)\n", numPontos);

                        Ponto_lista(numPontos, pontos,-1); //Função que Imprime os vetores.

                        printf("\nDigite o indice do ponto a ser liberado:");
                        scanf("%d", &indice);
                        if (indice < 0 || indice > numPontos) {
                            printf("Ponto %d é invalida\n\n", indice);
                        }else {
                            indiceValido = 1;
                            for (int i = 0; i < numPontos; i++) {
                                if (i == indice) {
                                    for (int j = indice; j < numPontos; j++) {
                                        pontos[j] = pontos[j + 1];
                                    }
                                }
                            }
                            Ponto_libera(pontos[numPontos]);
                            numPontos--;
                        }

                    }else {
                        printf("Não há pontos para serem liberados.\n");
                        indiceValido = 1;
                    }
                }
                break;

            case 3:
                Ponto_lista(numPontos, pontos, -1);
                break;

            case 4:
                int indice; float xtt, ytt;
                printf("4 - Atribuir Ponto\n");
                if (numPontos > 0) {
                    while (indiceValido == 0) {
                        Ponto_lista(numPontos, pontos, -1);
                        printf("Digite o indice do ponto no qual deseja atribuir novos valores: ");
                        scanf("%d", &indice);
                        if (indice >= 0 && indice < numPontos) {
                            indiceValido = 1;

                            printf("Digite o novo valor de x:");
                            scanf("%f",&xtt);

                            printf("Digite o novo valor de y:");
                            scanf("%f",&ytt);

                            Ponto_atribui(pontos[indice], xtt, ytt);
                            printf("Novos valores foram atribuidos com sucesso!\n");
                            Ponto_lista(numPontos, pontos, -1);
                        }else {
                            printf("Indice invalido.\n");
                            indiceValido = 0;
                        }
                    }
                }else {
                    printf("Não há pontos para serem atribuidos novos valores.\n");
                }
                break;

            case 5:
                int indice1, indice2;
                printf("5 - Distancia de dois pontos\n");
                if (numPontos < 2) {
                    printf("Não há pontos suficientes \n ");
                }else {
                    Ponto_lista(numPontos, pontos,-1);
                    printf("Escolha o indice do primeiro ponto:");
                    scanf("%d", &indice1);
                    Ponto_lista(numPontos, pontos, indice1);
                    printf("Escolha o indice do segundo ponto:");
                    scanf("%d", &indice2);
                    if (indice2 == indice1 || (indice1 < 0  || indice1 > numPontos) || (indice1 < 0  || indice1 > numPontos)  ) {
                        printf("Indice Invalido.");
                    }else {
                        printf("A distancia entre os pontos %d e %d é %f.\n", indice1,indice2,Ponto_distancia(pontos[indice1], pontos[indice2]));
                    }

                }

                break;
        }
    }
}