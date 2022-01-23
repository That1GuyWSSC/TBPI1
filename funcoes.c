/**
 * @file funcoes.c
 * @author Joao Machado
 * @author Diogo Espirito Santo
 * @author Tiago Fernandes
 * @brief Ficheiro que contem as funcoes do programa.
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "structs.h"
#include <string.h>
#include "funcoes.h"
#include <stdlib.h>

/**
 * @brief 
 * 
 * @param array 
 * @param index 
 * @param ordem 
 * @param nif 
 * @param codigo 
 * @param tempo 
 * @param distancia 
 * @return int 
 */
int insertPedido(Pedido array[],int index, int ordem, int nif, char *codigo, int tempo, int distancia){
/*    if(existePedido(array, index, ordem) == 1) 
    {
        printf("Ja existe;");
        return 0;
        exit(1);
    }
*/

    if (index < TAMANHOARR) {
        
   
    array[index].ordem = ordem;
    array[index].nif = nif;
    array[index].tempo= tempo;
    array[index].distancia= distancia;
    strcpy(array[index].codigoped, codigo);
    return 1;
    }
    return 0;
}    


void printarrayped(Pedido array[], int i)
{
    printf("%d %d %s %d %d \n", array[i].ordem, array[i].nif, array[i].codigoped, array[i].tempo, array[i].distancia);
}

void readfromfileinsertPedido(Pedido array[]){
    FILE *input_file;
    int ordem , nif , tempo , distancia;
    int c = 0;
    char codigo[TAMANHOSTR];

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

int insertMobilidade(Mobilidade array[], int index, char *codigo, char *tipo, float custo, int autonomia)
{
    if (index < TAMANHOARR) {
        strcpy(array[index].codigomobi, codigo);
    strcpy(array[index].tipo, tipo);
    array[index].custo = custo;
    array[index].autonomia = autonomia;
    return 1;
    }
    return 0;
    }

void printarrayMobilidade(Mobilidade array[], int i)
{
    printf("%s %s %.2f %d \n", array[i].codigomobi,array[i].tipo,array[i].custo,array[i].autonomia);
}

void printartudoMob(Mobilidade array[]){

    for (int i=0; array[i].custo != -1; i++) {
        printf("********************\n");
        printf("O custo da Mobilidade: %s \n ", array[i].codigomobi);
        printf("O tipo da Mobilidade %s \n", array[i].tipo);
        printf("O custo da Mobilidade: %.2f \n", array[i].custo);
        printf("A autonomia da Mobilidade: %d \n", array[i].autonomia);
        printf("********************\n");
        printf("\n");
    }

}

void readfromfileinsertMobilidade(Mobilidade array[]){

    char codigo[TAMANHOSTR];
    char tipo[TAMANHOSTR];
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
            //printf("%s %s %.2f %d \n", codigo, tipo , custo, autonomia);
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
    printf("*\t4- Remover um meio de mobilidade                     *\n");
    printf("*\t5- Inserir novo Pedido                               *\n");
    printf("*\t6- Remover um Pedido                                 *\n");
    printf("*\t7- Listar todos os meios de mobilidades              *\n");
    printf("*\t8- Listar todos os pedidos                           *\n");
    printf("*\t12- Armazenar os pedidos em file                     *\n");
    printf("*\t13- Armazenar as mobilidades em file                 *\n");
    printf("*\t14- Clear ao ecra                                    *\n");
    printf("*************************************************************\n");
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

void storeinfileped(Pedido array[]){
    FILE *input_file;
    input_file = fopen("pedidosafter.txt", "wt");
    if (input_file == NULL) {
        printf("Ocorreu um erro na abertura do ficheiro");
        exit(1);
    }
    else {
       {    for (int i=0; array[i].ordem != -1; i++) {
            fprintf(input_file, "%d ", array[i].ordem);
            fprintf(input_file, "%d ", array[i].nif);
            fprintf(input_file, "%s ", array[i].codigoped);
            fprintf(input_file, "%d ", array[i].tempo);
            fprintf(input_file, "%d\n", array[i].distancia);
        }
    }
    printf("Armazenado com sucessso. \n");
    
    fclose(input_file);
}
}

void storeinfilemob(Mobilidade array[]){
    FILE *input_file;
    input_file = fopen("mobilidadeafter.txt", "wt");
    if (input_file == NULL) {
        printf("Ocorreu um erro na abertura do ficheiro");
        exit(1);
    }
    else {
        for (int i=0; array[i].custo !=-1; i++){ 
            fprintf(input_file, "%s ", array[i].codigomobi);
            fprintf(input_file, "%s ", array[i].tipo);
            fprintf(input_file, "%.2f ", array[i].custo);
            fprintf(input_file, "%d\n", array[i].autonomia);
        }
        }
   
    printf("Armazenado com sucessso. \n");

    fclose(input_file);
}

void deletemob(Mobilidade array[]){
    char codigo[TAMANHOSTR];

    printf("Insira o codigo da mobilidade : \n");
    scanf("%s", codigo);

    for (int i=0; array[i].custo != -1 ;i++) {
        if (strcmp(array[i].codigomobi, codigo) == 0 && array[i].custo != -1) {
                for (int j=i ; j< TAMANHOARR-1; j++) {
                /*strcpy(array[j].codigomobi, array[j+1].codigomobi);
                strcpy(array[j].tipo, array[j+1].tipo);
                array[j].custo = array[j+1].custo;
                array[j].autonomia = array[j+1].autonomia;
                    */
                array[j] = array[j+1];
                }
                break;
            
            }
        }
}
void deleteped(Pedido array[]){
    char codigo[TAMANHOSTR];

    printf("Insira o codigo dos pedidos : \n");
    scanf("%s", codigo);
    for (int i=0; array[i].ordem != -1; i++) { 
        if (strcmp(array[i].codigoped, codigo) == 0 && array[i].ordem != -1 ) {
            for (int j=i; j< TAMANHOARR-1; j++) {
                array[j] = array[j+1];
            }
        }
    }

}



void clearscreen(){

    system("clear");

}