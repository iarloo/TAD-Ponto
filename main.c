#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"
#define MAX_PONTOS 10

int main()
{
    int funcaoDesejada = 1;
    Ponto *pontos[MAX_PONTOS]; // vetor pra guardar os pontos
    int numPontos = 0; //indicador  de quantos pontos eu ja tenho


    while(funcaoDesejada < 5 && funcaoDesejada > 0){
        printf("Operações:\n");
        printf("Numero Máximo de pontos : %d\n", MAX_PONTOS - numPontos1);
        printf("1 - Criar Ponto\n");
        printf("2 - Libera Ponto\n");
        printf("3 - Acessa Ponto\n");
        printf("4 - Atribuir Ponto\n");
        printf("5 - Distancia de dois pontos\n");

        //Recolhe a função desejada do usuario;
        scanf("%d", &funcaoDesejada);
        limpaTela();
        switch(funcaoDesejada){
            case 1:
                limpaTela();
                float x,y;
                printf("1 - Criar Ponto\n");
                printf("Digite as coordenadas de seu ponto\n");
                printf("Digite o valor x  :"); scanf("%f", &x);
                printf("Digite o valor y :"); scanf("%f", &y);

                if(numPontos < MAX_PONTOS){
                    pontos[numPontos] = Ponto_cria(x,y);
                    printf("Ponto %d criado: (%.1f, %.1f)\n", numPontos + 1, x, y);
                    numPontos++;
                }else{
                    printf("Numero maximo de pontos atingido, será criados novos pontos uma vez que algum ponto pré existente é liberado.\n");
                }
                break;

            case 2:
                if (numPontos > 0) {
                    int indice;
                    printf("Digite o indice do a ser liberado ( 1 a %d)\n", numPontos);


                }


        }

    }

   /* float d;
    Ponto *p,  *q;
    p = Ponto_cria(10,21);
    q = Ponto_cria(7,25);
    d = Ponto_distancia(p,q);
    printf("distancia entre pontos: %.1f \n", d);
    Ponto_libera(q);
    Ponto_libera(p);
    return 0;*/
}