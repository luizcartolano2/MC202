#include "lab.h"

int main(int argc, char const *argv[]) {
  //variables declaration
  int numb_elem;
  node *graph;
  int k;
  int i,j;

  //here we gonna read the number of elements and create the pointers vector
  scanf("%d",&numb_elem);
  graph = malloc((numb_elem+1) * sizeof(node));
  if(!graph)
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

  Print(graph,numb_elem);

  return 0;
}
