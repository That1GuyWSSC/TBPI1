#include <stdio.h>
#include "structs.h"
#include <string.h>
#include "funcoes.h"
#include <stdlib.h>


int insertPedido(Pedido array[],int index, int ordem, int nif, char *codigo, int tempo, int distancia){
/*    if(existePedido(array, index, ordem) == 1) 
    {
        printf("Ja existe;");
        return 0;
        exit(1);
    }
*/


    array[index].ordem = ordem;
    array[index].nif = nif;
    array[index].tempo= tempo;
    array[index].distancia= distancia;
    strcpy(array[index].codigoped, codigo);

    return 1;

}    


void printarrayped(Pedido array[], int i)
{
    printf("%d %d %s %d %d \n", array[i].ordem, array[i].nif, array[i].codigoped, array[i].tempo, array[i].distancia);
}

void readfromfileinsertPedido(Pedido array[]){
    FILE *input_file;
    int ordem , nif , tempo , distancia;
    int c = 0;
    char codigo[100];

    input_file = fopen("pedidos.txt", "rt");
    
    if (input_file == NULL)
    {
        printf("Ocorreu um erro no a abrir o ficheiro");
        exit(1);
    }
        while (!feof(input_file) )
        {
            fscanf(input_file,"%d %d %s %d %d\n", &ordem , &nif , codigo, &tempo, &distancia);
            //printf("%d %d %s %d %d \n", ordem , nif , codigo , tempo , distancia);
            
            insertPedido(array, c ,ordem, nif, codigo, tempo, distancia);
            printarrayped(array, c);
            
            c++;
        }

    fclose(input_file);
    
}

/*int existePedido(Pedido array[], int index, int ordem){
    for (int i = 0; i < index; i++)
    {
         if (array[index].ordem == ordem) return 1;
         else return 0;
    
    }
}
*/

void insertMobilidade(Mobilidade array[], int index, char *codigo, char *tipo, float custo, int autonomia)
{
    strcpy(array[index].codigomobi, codigo);
    strcpy(array[index].tipo, tipo);
    array[index].custo = custo;
    array[index].autonomia = autonomia;
}

void printarrayMobilidade(Mobilidade array[], int i)
{
    printf("%s %s %.2f %d \n", array[i].codigomobi,array[i].tipo,array[i].custo,array[i].autonomia);
}

void readfromfileinsertMobilidade(Mobilidade array[]){

    char codigo[100];
    char tipo[100];
    float custo;
    int autonomia;   
    int index = 0;

    FILE *input_file;
    input_file = fopen("mobilidades.txt", "r");

    if(input_file == NULL)
    {
        printf("Ocorreu um erro a abrir o ficheiro");
        exit(1);
    }
    else
        while(!feof(input_file))
        {
            fscanf(input_file,"%s %s %f %d\n", codigo, tipo, &custo, &autonomia);
            printf("%s %s %.2f %d \n", codigo, tipo , custo, autonomia);
            insertMobilidade(array, index, codigo, tipo, custo, autonomia);
            printarrayMobilidade(array, index);
            index++;
        }

    fclose(input_file);
}


int menu(){
    int opcao;
    printf("\n");
    printf("**********************MENU***********************************\n");
    printf("*\t1- Ler o ficheiro de pedidos                         *\n");
    printf("*\t2- Ler o ficheiro de meio de mobilidade              *\n");
    printf("*\t3- Inserir um novo meio de mobilidade                *\n");
    printf("*\t4- Remover um pedido de mobilidade                   *\n");
    printf("*\t5- Inserir novo Pedido                               *\n");
    printf("*\t6- Remover um Pedido                                 *\n");
    printf("*\t7- Listar todos os meios de mobilidades              *\n");
    printf("*\t8- Listar todos os pedidos                           *\n");
    printf("*\t9- Calculo do custo de um pedido a partir de um número de ordem; *\n");
    printf("********************************************************\n");
    printf("Escreva o numero da opcao desejada.\n");
    scanf("%d", &opcao);

return (opcao);
}

void printartudoPedido(Pedido array[]){

    //readfromfileinsertPedido(array);

    for (int i = 0; array[i].ordem != -1; i++) {
        printf("********************\n");
        printf("A ordem do pedido: %d \n ", array[i].ordem);
        printf("O nif do pedido %d \n", array[i].nif);
        printf("O codigo do pedido: %s \n", array[i].codigoped);
        printf("O tempo do pedido: %d \n", array[i].tempo);
        printf("A distancia do pedido: %d \n", array[i].distancia);
        printf("********************\n");
        printf("\n");
    }

}