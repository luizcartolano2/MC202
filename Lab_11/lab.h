//
//
//    Created by Luiz Cartolano
//    RA: 183012
//    Program to implement a minimun heap in C
//
//

#ifndef lab_11
#define  lab_11

int tamanho_heap,n;

#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
	int chave;
	int custo;
}heap;


//functions that will operate the heap
void h_insert(heap vetor_heap[], int chave, int custo, int *point_tamanho);
heap h_remove(heap vetor_heap [], int *point_tamanho);
void h_reduce();
heap* create_heap();

#endif
