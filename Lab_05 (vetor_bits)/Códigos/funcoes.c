//
//
//  Created by Luiz Eduardo Cartolano
//  RA: 183012
//
//

#include "lab05.h"

void create(unsigned char **vet){
  //funcao que cria o vetor de unsigned char
  // unsigned char *vet;
  if((*vet) == NULL){
    scanf("%d",&n);
    if(n % 8 != 0)
      (*vet) = calloc((n/8)+1,sizeof(unsigned char));
    else
      (*vet) = calloc((n/8),sizeof(unsigned char));
  }else{
    free(*vet);
    (*vet) = NULL;
    n_elements = 0;
    scanf("%d",&n);
    if(n % 8 != 0)
      (*vet) = calloc((n/8)+1,sizeof(unsigned char));
    else
      (*vet) = calloc((n/8),sizeof(unsigned char));
  }

}

void add(unsigned char **vet){
  //funcao responsavel por inserir um numero no vetor de bits
  //para isso usaremos operadores com bits, o primeiro para "transformar" o numero em "binario" e o outro para "adiciona-lo" ao vetor
  int i, k, pos;

  scanf("%d",&k);

  if((*vet == NULL) || (n == 0))
    return;

  else{

    i = k/8;
    pos = k % 8;
    (*vet)[i] = (*vet)[i] | (1 << pos);
    n_elements++;
  }
}

void remov(unsigned char **vet){
  //funcao que remove um elemento do vetor de bit, primeiro transformando o numero em "binario" e depois usando o operador logico para remove-lo
  int k;

  scanf("%d",&k);

  if((*vet == NULL) || (n_elements == 0))
    return;

  else{
    (*vet)[k/8] &= ~(1 << (k%8));
    n_elements--;
  }
}

int in(unsigned char **vet, int k){
  //funcao que verifica se um numero está ou nao inserido no vetor de bits

  if((*vet == NULL) || (n_elements == 0))
    return 0;

  else{
    return (((*vet)[k/8] & (1 << (k % 8))) != 0);
  }
}

int rank(unsigned char **vet, int k){
  
  int i, contador = 0;

    for(i = 0; i <= k; i++){
      if(in(vet,i))
        contador++;
    }

    return contador;

}

void print(unsigned char **vet){

  int i, aux;

  printf("S = {");

  aux = n_elements;
  for(i = 0; i <= n; i++){
    if(aux == 1){
      if(in(vet,i))
        printf("%d",i);
    }
    else{
      if(in(vet,i)){
          printf("%d,",i);
          aux--;
        }
      }
    }
    printf("}\n");
  }

int sele(unsigned char **vet, int num){

  int i , count;

  for(i = 0 ,count = 0; count != num; i++){
    if(in(vet,i))
      count++;
  }

  return i - 1;

}

int rangecount(unsigned char **vet, int pos1, int pos2){

  int i, j = pos1, k = pos2, count = 0;

  for(i = j; i <= k; i++){
    if(in(vet,i))
      count++;
  }

  return count;

}
