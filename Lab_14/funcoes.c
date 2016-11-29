#include "lab.h"

node *create_node(int vert){
  //here we allocate the node, if it fails we warning the guy that is using your program
  node *new_node = calloc(1,sizeof(node));
  if(!new_node)
    printf("Error in the allocation of the new node\n");

  //here we initialize the struct
  new_node->vert = vert;
  new_node->next = NULL;

  return new_node;

}

void insertList(int *** graf, int vert_i, int vert_j){}
