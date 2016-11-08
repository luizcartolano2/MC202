#include "stdio.h"
#include "stdlib.h"

typedef struct data{
  int line;
  int collum;
  int value;
}data;

int main(int argc, char const *argv[]) {
  int k, i, line_m = 0;
  int *A, *R, *C;
  data *entradas;

  scanf("%d",&k);
  entradas = malloc(k * sizeof(data));
  if(!entradas)
    printf("memória insuficiente\n");

  for(i = 0; i < k; i++){
    scanf("%d %d %d",&(entradas[i]).line,&(entradas[i]).collum,&(entradas[i]).value);
    if(line_m < entradas[i].line)
      line_m = entradas[i].line;
  }

  A = malloc(k * sizeof(int));
  R = malloc((line_m+1) * sizeof(int));
  C = malloc(k * sizeof(int));
  if((!A) || (!R) || (!C))
    printf("memória insuficiente\n");

  return 0;

}
