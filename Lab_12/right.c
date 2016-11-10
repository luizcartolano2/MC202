#include "stdio.h"
#include "stdlib.h"

typedef struct data{
  int line;
  int collum;
  int value;
}data;

int main(int argc, char const *argv[]) {
  int k, n_line = 0, n_collum = 0; /*nonzero entrys, number of lines, number of collums*/
  int i;
  int *row_ptr, *vals, *col_ind;
  data *entradas;

  scanf("%d",&k);
  entradas = malloc(k * sizeof(data));
  if(!entradas)
    printf("memória insuficiente\n");

  for(i = 0; i < k; i++){
    scanf("%d %d %d",&(entradas[i]).line,&(entradas[i]).collum,&(entradas[i]).value);
    if(n_line < entradas[i].line)
      n_line = entradas[i].line;
    if(n_collum < entradas[i].collum)
      n_collum = entradas[i].collum;
  }

  row_ptr = malloc(k * sizeof(int));
  vals = malloc((n_line+1) * sizeof(int));
  col_ind = malloc(k * sizeof(int)); 
  if((!row_ptr) || (!vals) || (!col_ind))
    printf("memória insuficiente\n");

  for(i = 0; i < k;i++){
    row_ptr[i] = (entradas[i]).value;
    col_ind[i] = (entradas[i]).collum;

  }

  return 0;

}
