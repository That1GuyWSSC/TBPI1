/**
 * @file main.c
 * @author Joao Machado
 * @author Diogo Espirito Santo
 * @author Tiago Fernandes
 * @brief Ficheiro principal do programa, onde e executando
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "structs.h"
#include "funcoes.h"
#include <stdlib.h>
#include <string.h>


/**
 * @brief Funcao que corre o programa
 * 
 * @return int 
 */
int main(void){
int opcao, i, nif, tempo, distancia, ordem;
int  custo, autonomia;
int index;
char codigo[TAMANHOSTR];
char tipo[TAMANHOSTR];

    Pedido array[TAMANHOARR];
    preencherPed(array);
    Mobilidade array2[TAMANHOARR];
    preencherMob(array2);
    do {
          opcao = menu();
    switch (opcao) {
    case 1 : readfromfileinsertPedido(array);
                break;
    case 2 : readfromfileinsertMobilidade(array2);
                break;
    case 3 : for (i=0; array2[i].custo != -1; i++);
            printf("Insira o codigo : \n");
            scanf("%s", codigo);
            printf("Insira o tipo : \n");
            scanf("%s", tipo);
            printf("Insira o custo : \n");
            scanf("%d", &custo);
            printf("Insira a autonomia : \n");
            scanf("%d", &autonomia);
    
            insertMobilidade(array2,i, codigo, tipo , custo, autonomia);
            break;
    case 4 : deletemob(array2);
            break;
    case 5 :  for (i=0; array[i].ordem != -1; i++);
            printf("Insira o numero do pedido\n");
            scanf("%d", &ordem);
            printf("Insira o nif\n");
            scanf("%d", &nif);
            printf("Insira o codigo\n");
            scanf("%s", codigo);
            printf("Insira o tempo\n");
            scanf("%d", &tempo);
            printf("Insira a distancia\n");
            scanf("%d", &distancia);
            //printf("%d %d %s %d %d index : %d ", ordem, nif, codigo, tempo,distancia, i);
            insertPedido(array,i, ordem, nif, codigo, tempo, distancia);
            break;
    case 6 : deleteped(array);
            break;
    case 7 ://insertMobilidade(array2,i, codigo, tipo , custo, autonomia);
            printartudoMob(array2);
            break;

    case 8 : //insertPedido(array,i, ordem, nif, codigo, tempo, distancia); 
            printartudoPedido(array);
            break;
    case 9 : calcusto(array, array2);
            break;
    case 12 : storeinfileped(array);
            break;
    case 13: storeinfilemob(array2);
            break;
    case 14: clearscreen();
            break;

    default:
        printf("Ocorreu um erro.");
        break;
    }
}while (opcao!=0);
}
