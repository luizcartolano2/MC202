//
//
//    Created by Luiz Cartolano
//    RA: 183012
//
//
#ifndef lab
#define lab


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definição da estrutura dos nós da árvore
typedef struct arv{
  int data;
  struct arv *left;
  struct arv *right;
}arv;

//funções de impressão
void pre_ordem_print(arv *Arv);
void em_ordem_print(arv *Arv);
void pos_ordem_print(arv *Arv);
void arv_size(arv *Arv,int level);

//funções auxiliares
arv* arv_lib(arv *a);
int height(arv *Arv);
arv* sucessor(arv *Arv);
arv* create(int dado);

//funções de busca
arv* search(arv *Arv, int dado);
arv* minimo(arv *Arv);
arv* maximo(arv *Arv);

//funções de manipulação da árvore
arv* insert(arv *Arv, arv *new);
arv* delete(arv *Arv, int dado);

#endif
