//
//
//  Created by Luiz Eduardo Cartolano
//  RA: 183012
//
//

#ifndef lab03_h
#define lab03_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    double value;
    struct node *A;
    struct node *B;

}node;

//funcao que insere os elementos de maneira ordenada na lista
void insert(node **L,int pos,double element);

//funcao que destroi a lista
void destruct(node **L);

//funcao que imprime a lista
void print_list(node **L);

//funcao que inverte a lista entre duas posicoes especificas
void revert(node **L, int pos1, int pos2);

#endif /* lab03_h */
