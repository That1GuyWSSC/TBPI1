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
 * @brief Funcao que passa por argumentos todos os elementos necessarios para inserir um novo elemento no array de structs de Pedido
 * 
 * @param array array da struct Pedido
 * @param index index do array 
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

/**
 * @brief funcao que escreve na consola um elemento do array 
 * 
 * @param array array da struct do Pedido
 * @param i 
 */
void printarrayped(Pedido array[], int i)
{
    printf("%d %d %s %d %d \n", array[i].ordem, array[i].nif, array[i].codigoped, array[i].tempo, array[i].distancia);
}
/**
 * @brief Funcao que le os dados do ficheiro "pedidos" e insere os valores obtidos num array dos registos e escreve na consola para confirmar os valores
 * 
 * @param array array da struct do Pedido 
 */
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
/**
 * @brief Funcao que pode vir a ser utilizada para verificar a existencia de um elemento do array 
 * 
 */
/*int existePedido(Pedido array[], int index, int ordem){
    for (int i = 0; i < index; i++)
    {
         if (array[index].ordem == ordem) return 1;
         else return 0;
    
    }
}
*/

/**
 * @brief Funcao que passa por argumentos todos os valores necessarios para preencher o elemento da struct da mobilidade 
 * 
 * @param array array da struct da Mobilidade
 * @param index 
 * @param codigo 
 * @param tipo 
 * @param custo 
 * @param autonomia 
 * @return int 
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
/**
 * @brief Funcao que escreve na consola um elemento de um certo index do array
 * 
 * @param array array da struct de Mobilidade
 * @param i 
 */
void printarrayMobilidade(Mobilidade array[], int i)
{
    printf("%s %s %.2f %d \n", array[i].codigomobi,array[i].tipo,array[i].custo,array[i].autonomia);
}
/**
 * @brief Funcao que escreve na consola todos os elementos do array
 * 
 * @param array array da struct de Mobilidade
 */
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
/**
 * @brief Funcao que le os dados do ficheiro de mobilidades e insere os dados num array de registos da struct, escreve tambem na consola para verificar se os elementos passados foram os corretos
 * 
 * @param array array da struct de Mobilidade
 */
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

/**
 * @brief Funcao utilizada para escrever na consola o nosso menu (apresenta todas as opcoes disponiveis para o utilizador usar)
 * 
 * @return int <- a opcao inserida pelo o utilizador
 */
int menu(){
    int opcao;
    printf("\n");
    printf("**********************MENU*********************************************\n");
    printf("*\t1- Ler o ficheiro de pedidos                                  *\n");
    printf("*\t2- Ler o ficheiro de meio de mobilidade                       *\n");
    printf("*\t3- Inserir um novo meio de mobilidade                         *\n");
    printf("*\t4- Remover um meio de mobilidade                              *\n");
    printf("*\t5- Inserir novo Pedido                                        *\n");
    printf("*\t6- Remover um Pedido                                          *\n");
    printf("*\t7- Listar todos os meios de mobilidades                       *\n");
    printf("*\t8- Listar todos os pedidos                                    *\n");
    printf("*\t9- Cálculo do custo ligado a um pedido do seu número de ordem *\n");
    printf("*\t12- Armazenar os pedidos em file                              *\n");
    printf("*\t13- Armazenar as mobilidades em file                          *\n");
    printf("*\t14- Clear ao ecra                                             *\n");
    printf("***********************************************************************\n");
    printf("Escreva o numero da opcao desejada.\n");
    scanf("%d", &opcao);

return (opcao);
}
/**
 * @brief Funcao que escreve na consola todos os elementos do array de registos de uma struct
 * 
 * @param array array da struct dos Pedidos
 */
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

/**
 * @brief Funcao usada no final do programa para escrever todos os elementos do array de registo de pedidos, para um outro ficheiro 
 * 
 * @param array arrat da struct dos Pedidos
 */
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
/**
 * @brief Funcao utilizada no final do programa para escrever num ficheiro todos os elementos do array de registos da struct especifica, para um outro ficheiro
 * 
 * @param array array da struct da Mobilidade
 */
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
/**
 * @brief Funcao que apaga elementos do array utilizando o codigo dos elementos como parametro para apagar
 * 
 * @param array array da struct de Mobilidade
 */
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
/**
 * @brief Funcao que apaga todos os elementos do array de registo, se o codigo fornececido for igual a um dos elementos
 * 
 * @param array array da struct de Pedido
 */
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


/**
 * @brief Funcao utilizada para a limpeza do ecra, para melhor a visibilidade do menu
    Funciona so em Linux
 * 
 */
void clearscreen(){

    system("clear");

}
/**
 * @brief funcao que preenche o array com -1 nos numeros e espacos nos chars
 * 
 * @param array array de pedidos
 */
void preencherPed(Pedido array[]){
    
    for (int i=0; i<TAMANHOARR; i++) {
        array[i].ordem = -1;
        array[i].nif = -1;
        array[i].tempo= -1;
        array[i].distancia= -1;
        strcpy(array[i].codigoped, "");

    }

}
/**
 * @brief funcao que preenche o array com -1 nos numeros e espacos nos chars
 * 
 * @param array array de mobilidade
 */
void preencherMob(Mobilidade array[]){

    for (int i=0; i<TAMANHOARR; i++) {
        strcpy(array[i].codigomobi, "");
        strcpy(array[i].tipo, "");
        array[i].custo = -1;
        array[i].autonomia = -1;
        }

}
/**
 * @brief Funcao que utiliza o numero de ordem inserido para calcular o custo associado a essa mobilidade eletrica
 * 
 * @param array array da struct de Pedidos  
 * @param array2 array da struct de Mobiliadades
 */
void calcusto(Pedido array[], Mobilidade array2[]){
    int ordem;
    printf("Insira o numero de ordem pretendido: \n");
    scanf("%d",&ordem);

    int aux=0;
    for (int i=0; array[i].ordem != -1; i++) {
        if (array[i].ordem == ordem) {
            for (int j=0; array2[j].custo != -1; j++) {
             if (strcmp(array[i].codigoped, array2[j].codigomobi) == 0 ){
             //printf("%s %s %.2f %d", array2[j].codigomobi, array2[j].tipo, array2[j].custo, array2[j].autonomia); teste
             printf("O custo associado a numero de ordem inserido e de : %.2f", array2[j].custo);
             aux=1;
             //break;
             }
            }
        }
   if (aux==1) {
    break;
    
    }   
    }
}