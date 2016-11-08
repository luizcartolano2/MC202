#include "stdio.h"
#include "stdlib.h"

typedef struct data{
  int line;
  int collum;
  int value;
}data;

typedef struct row{
  int collum_ind;
  int valor;
}row;

typedef struct line{
  int line_ind;
  row *p_row;
}line;

int main(int argc, char const *argv[]) {
  int k, i;
  data *entradas;
  row *Row;
  line *Lines;

  scanf("%d",&k);
  entradas = malloc(k * sizeof(data));
  if(!entradas)
    printf("memória insuficiente\n");
  Row = malloc(k * sizeof(row));
  if(!Row)
    printf("memória insuficiente\n");  

  for(i = 0; i < k; i++)
    scanf("%d %d %d",&(entradas[i]).line,&(entradas[i]).collum,&(entradas[i]).value);

  return 0;

}
