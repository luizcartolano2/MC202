#include "lab.h"

void insertList(node *graph, int i, int j){
  gpt *aux = malloc(sizeof(gpt));

  aux->no = &graph[j];
  aux->next = graph[i].list;
  graph[i].list = aux;

  return;

}

void DFS(node *graph, int size){
  int i;

  tim3 = 0;
  for(i = 1; i <= size; i++)
    if(!graph[i].color)
      DFS_Visit(graph,i,size);

}

void DFS_Visit(node *graph,int i, int size){
  ped[ped_i++] = i;
  tim3++;
  graph[i].ti = tim3;
  graph[i].color = 1;

  gpt *aux = graph[i].list;

  while (aux) {
    if(!aux->no->color)
      DFS_Visit(graph,aux->no->vert,size);
    if(aux->no->color == 1)
      ciclica = 1;
    aux = aux->next;
  }

  graph[i].color = 2;
  tim3++;
  graph[i].tf = tim3;
}
