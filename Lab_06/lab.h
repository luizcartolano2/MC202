//
//
//    Created by Luiz Cartolano
//    RA: 183012
//
//
#ifndef lab
#define lab

int preIndice;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct arv{
  char data;
  struct arv *left;
  struct arv *right;
}arv;

void arv_print(arv *a);
arv* arv_lib(arv *a);
arv* arv_build(char ordem[], char pre[], int ordem_in, int ordem_fim);

#endif
