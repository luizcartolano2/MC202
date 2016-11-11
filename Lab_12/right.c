#include "stdio.h"
#include "stdlib.h"

typedef struct data{
  int line;
  int collum;
  int value;
}data;

typedef struct {
  int *val;
	int *col_ind;
	int *row_ptr;
	int val_length;
	int row_ptr_length;
	int rows;
	int cols;
}csr;

int main(int argc, char const *argv[]) {
  int i;
  data *entradas;
  csr *CRS;

  CRS = malloc

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

  return 0;

}
