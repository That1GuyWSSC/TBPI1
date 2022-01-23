/**
 * @file structs.h
 * @author Joao Machado
 * @author Diogo Espirito Santo
 * @author Tiago Fernandes
 * @brief Ficheiro que contem as "structs" do programa todo
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

typedef struct 
{
    char codigomobi[100];
    char tipo[100];
    float custo;
    int autonomia;
}Mobilidade;

typedef struct 
{
    int ordem;
    int nif;
    char codigoped[100];
    int tempo;
    int distancia;
}Pedido;




