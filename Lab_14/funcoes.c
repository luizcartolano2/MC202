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

node* insertList(node *graf, int vert_i, int vert_j){
  int i = vert_i;
  node *aux = graf;
  //call the function that create a new node
  node *new = create_node(vert_j);

  new->next = aux[i].next;
  aux[i].next = new;

  return aux;
}

void Print(node *graf, int size){
  int i;
  node *aux = graf;

  for(i = 1; i<=size;i++){
    printf("[%d]",aux[i].vert);
    while (aux[i].next) {
      printf("->%d",aux[i].next->vert);
      aux[i].next = aux[i].next->next;
    }
    printf("\n");
  }

  return;

}

void DFS(node *graf, int size){
  int i, tim3;
  node *aux = graf;

  tim3 = 0;
  for(i = 1; i<=size;i++){
    if(aux.color == 0)
      DFS_Visit(graf,graf[i].next);
  }
}

void DFS_Visit(node *graf,node *u){
  int tim3;
  node *aux = u;

  tim3++;
  u.d = tim3;
  u.color = 1;

  while (aux->next) {
    if(aux->color == 0)
      DFS_Visit(graf,aux->next);
    aux = aux->next;
  }
  u.color = 2;
  tim3++;
  u.f = tim3;

}
