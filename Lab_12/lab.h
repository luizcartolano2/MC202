//
//
//    Created by Luiz Cartolano
//    RA: 183012
//    Program to implement a "matriz esparsa" in C
//
//

#ifndef lab
#define  lab

typedef struct node{
  int line;
  int collum;
  int value;
  struct node* lines;
  struct node* collums;
}node;

node* first_e;

#include <stdio.h>
#include <stdlib.h>

void print_list(node *list);
node* new_node(int line, int collum, int value);
void m_insert(node* new_node);
node* verify_node(int line, int collum);

#endif /*lab*/
