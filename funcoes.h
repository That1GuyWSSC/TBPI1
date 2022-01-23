/**
 * @file funcoes.h
 * @author Joao Machado
 * @author Diogo Espirito Santo
 * @author Tiago Fernandes
 * @brief Ficheiro .h onde estao as assinaturas das funcoes do ficheiro.c .
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// new .h
extern void readfromfileinsertPedido(Pedido array[]);
extern void printarrayMobilidade(Mobilidade array[], int i);
extern void readfromfileinsertMobilidade(Mobilidade array[]);
extern void printartudoPedido(Pedido array[]);
extern void printartudoMob(Mobilidade array[]);
extern void storeinfileped(Pedido array[]);
extern void storeinfilemob(Mobilidade array[]);
extern void deletemob(Mobilidade array[]);
extern void clearscreen();
extern void deleteped(Pedido array[]);
extern void preencherPed(Pedido array[]);
extern void preencherMob(Mobilidade array[]);
extern int insertMobilidade(Mobilidade array[], int index, char *codigo, char *tipo, float custo, int autonomia);
extern int insertPedido(Pedido array[],int index, int ordem, int nif, char *codigo, int tempo, int distancia);
extern int menu();