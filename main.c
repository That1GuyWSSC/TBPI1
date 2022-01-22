#include <stdio.h>
#include "structs.h"
#include "funcoes.h"
#include <stdlib.h>
#include "string.h"



int main(void){
int opcao, i, nif, tempo, distancia, ordem;
int  custo, autonomia;
char codigo[TAMANHOSTR];
char tipo[TAMANHOSTR];

    Pedido array[TAMANHOARR];
    for (i=0; i<TAMANHOARR; i++) {
        array[i].ordem = -1;
        array[i].nif = -1;
        array[i].tempo= -1;
        array[i].distancia= -1;
        strcpy(array[i].codigoped, "");

    }
    Mobilidade array2[TAMANHOARR];
        for (i=0; i<TAMANHOARR; i++) {
        strcpy(array2[i].codigomobi, "");
        strcpy(array2[i].tipo, "");
        array2[i].custo = -1;
        array2[i].autonomia = -1;
        }
    int index;

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
    case 4 : 
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
            printf("%d %d %s %d %d index : %d ", ordem, nif, codigo, tempo,distancia, i);
            insertPedido(array,i, ordem, nif, codigo, tempo, distancia);
            break;
    case 6 :
    case 7 :insertMobilidade(array2,i, codigo, tipo , custo, autonomia);
            printartudoMob(array2);
            break;

    case 8 : insertPedido(array,i, ordem, nif, codigo, tempo, distancia); 
            printartudoPedido(array);
            break;
    case 12; stor
            break;
    case 13:
            break;

    default:
        printf("Tente outra vez");
        break;
    }
}while (opcao!=0);
}
