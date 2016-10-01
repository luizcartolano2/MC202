//
//
//  Created by Luiz Eduardo Cartolano
//  RA: 183012
//
//

#ifndef nabo
#define nabo

int n_elements, n;


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void create(unsigned char **vet);
void add(unsigned char **vet);
void remov(unsigned char **vet);
int in(unsigned char **vet, int k);
int rank(unsigned char **vet, int k);
void print(unsigned char **vet);
int sele(unsigned char **vet, int num);
int rangecount(unsigned char **vet, int pos1, int pos2);

#endif /* nabo */
