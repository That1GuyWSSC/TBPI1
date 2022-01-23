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

#define TAMANHOARR 100
#define TAMANHOSTR 20


/**
 * @brief Struct que representa um meio de mobilidade eletrica
 * 
 */
typedef struct 
{
    char codigomobi[TAMANHOSTR];
    char tipo[TAMANHOSTR];
    float custo;
    int autonomia;
}Mobilidade;

/**
 * @brief Struct que representa os varios pedidos dos utilizadores
 * 
 */
typedef struct 
{
    int ordem;
    int nif;
    char codigoped[TAMANHOSTR];
    int tempo;
    int distancia;
}Pedido;




