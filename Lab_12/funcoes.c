//
//
//    Created by Luiz Cartolano
//    RA: 183012
//    Program to implement a "matriz esparsa" in C
//
//

#include "lab.h"

node* new_node(int line, int collum, int value){

  node* new = malloc(1 * sizeof(node));
  if(!new)
    printf("pruuuu\n");

  new->line = line;
  new->collum = collum;
  new->value = value;

  return new;

}

void m_insert(node* new){

  node *p = NULL;

  p = verify_node(new->line,new->collum);

  if(!p){
    if(!first_e){
      new->prox = NULL;
      first_e = new;
      return;
    }
    else{
      new->prox = first_e;
      first_e = new;
      return;
    }
  }
  else{
    // printf("o q ta acontecenu\n");
    // printf("line:%d\ncollum:%d\nvalue:%d\n",p->line,p->collum,p->value);
    return;
  }
}

node* verify_node(int line, int collum){

  node* aux = first_e;

  while (aux){
    if(((aux->line) == line) && (aux->collum == collum)){
      // printf("pruuuuuuuuuu\n");
      // printf("%d %d\n",line,collum);
      return aux;
    }
    aux = aux->prox;
  }

  return NULL;

}

void print_list(node *list){
  list = first_e;

  while (list) {
    printf("line: %d collum: %d value: %d\n",list->line,list->collum,list->value);
    list = list->prox;
  }
}
