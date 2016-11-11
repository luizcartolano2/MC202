#include "lab.h"

int main(int argc, char const *argv[]) {
  int k, i, max_row = 0;
  Head = NULL;
  data *entradas;
  csr *CSR;

  scanf("%d",&k);
  entradas = calloc(k,sizeof(data));
  CSR = calloc(1,sizeof(csr));
  if((!entradas) || (!CSR))
    printf("Error in the allocation of the entrys struct or in the CSR struct\n");

  for(i = 0; i < k; i++){
    scanf("%d %d %d",&(entradas[i]).line,&(entradas[i]).collum,&(entradas[i]).value);
    insert_node(entradas[i].line,entradas[i].collum,entradas[i].value);
    if(max_row < entradas[i].line)
      max_row = entradas[i].line;
  }
  free(entradas);

  CSR = create_csr(CSR,k,max_row);

  printa_tudo(Head);

  return 0;

}
