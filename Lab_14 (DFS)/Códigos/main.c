//
//
//      created by Luiz Cartolano
//      RA: 183012
//
//
#include "lab.h"

int main(int argc, char const *argv[]) {
  //variables declaration
  int numb_elem;
  node *graph;
  int k;
  int i,j;
  ciclica = 0;
  ped_i = 0;

  //here we gonna read the number of elements and create the pointers vector
  scanf("%d",&numb_elem);
  graph = malloc((numb_elem+1) * sizeof(node));
  ped = calloc(numb_elem,sizeof(int));
  if((!graph) || (!ped))
    printf("Error in the graph allocation\n");

  //here we initialize the graph vector with NULL
  for(k = 1; k <= numb_elem; k++){
    graph[k].vert = k;
    graph[k].list = NULL;
    graph[k].color = 0;
  }

  do{
    scanf("%d,%d",&i,&j);
    insertList(graph,i,j);
  }while ((i != 0) && (j != 0));

  DFS(graph,numb_elem);

  for (i = 0; i < numb_elem; i++)
    printf("%d [%d,%d]\n",graph[ped[i]].vert,graph[ped[i]].ti,graph[ped[i]].tf);

  if(ciclica)
    printf("aciclico: nao\n");

  else
    printf("aciclico: sim\n");

  return 0;

}
