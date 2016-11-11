#include "lab.h"

int main(int argc, char const *argv[]) {
  int k, i;
  Head = NULL;
  data *entradas;

  scanf("%d",&k);
  entradas = malloc(k * sizeof(data));
  if(!entradas)
    printf("memória insuficiente\n");

  for(i = 0; i < k; i++){
    scanf("%d %d %d",&(entradas[i]).line,&(entradas[i]).collum,&(entradas[i]).value);
    insert_node(entradas[i].line,entradas[i].collum,entradas[i].value);
  }

  printa_tudo(Head);

  return 0;

}
