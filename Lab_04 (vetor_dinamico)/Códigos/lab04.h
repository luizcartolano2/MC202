//
//
//  Created by Luiz Eduardo Cartolano
//  RA: 183012
//
//

#ifndef nabo
#define nabo

struct dados{
  int first_ele;
  int last_ele;
  int size;
}data;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* read_string();
void is_empty(char **vetor);
void print_first(char **vetor);
void print_last(char **vetor);
void push(char ***vetor);
void pop(char ***vetor);
char** verifica_vetor(char ***vetor);
char** dobra_vetor(char*** vetor);
char** diminui_vetor(char*** vetor);
void unshift(char ***vetor);
void shift(char ***vetor);

#endif /* nabo */
