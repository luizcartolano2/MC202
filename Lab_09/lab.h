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
  double p_right, p_left;
}arv;

arv* arv_build(arv *Arv,char s);
arv* arv_lib(arv *Arv);
double calc_peso(arv *Arv);

#endif /*lab*/
