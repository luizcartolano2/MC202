//
//
//    Created by Luiz Cartolano
//    RA: 183012
//    Program to implement a "matriz esparsa" in C
//
//

#include "lab.h"

node* new_node(int line, int collum, int value){

  node* new_node = malloc(1 * sizeof(node));
  if(!new_node)
    printf("pruuuu\n");

  new_node->line = line;
  new_node->collum = collum;
  new_node->value = value;

  return new_node;

}

void m_insert(node* new_node){
  
}
