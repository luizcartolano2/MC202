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
  struct node* n_line;
  struct node* n_collum;
}node;

node* new_node(int line, int collum, int value);
void m_insert(node* new_node);

#endif /*lab*/
