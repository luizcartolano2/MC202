#include "lab.h"

int main(int argc, char const *argv[]) {
  //variables declaration
  int numb_elem;
  node *graf;
  int k;
  int i,j;

  //here we gonna read the number of elements and create the pointers vector
  scanf("%d",&numb_elem);
  graf = malloc((numb_elem+1) * sizeof(node));
  if(!graf)
    printf("Error in the graph allocation\n");

  //here we initialize the graph vector with NULL
  for(k = 1; k <= numb_elem; k++){
    graf[k].vert = k;
    graf[k].next = NULL;
  }

  do{
    scanf("%d,%d",&i,&j);
    insertList(graf,i,j);
  }while ((i != 0) && (j != 0));

  Print(graf,numb_elem);

  return 0;
}
