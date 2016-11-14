#include "lab.h"

int main(int argc, char const *argv[]) {
  int k, i, max_row = 0, max_col = 0,row,col,val;
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
    if(max_col < entradas[i].collum)
      max_col = entradas[i].collum;
  }
  free(entradas);

  //printa_tudo(Head);
  CSR = create_csr(CSR,k,max_row);
  CSR->rows = max_row;
  CSR->cols = max_col;
  make_csr(Head,&CSR);

  print_CSR(CSR);

  while (1) {
    scanf("%d %d",&row,&col);
    if((row == -1) && (col == -1))
      break;
    val = find_csr(CSR,row,col);
    printf("(%d,%d) = %d\n",row,col,val);
  }

  destruct_list(&Head);
  CSR = free_CSR(CSR);
  free(CSR);

  return 0;

}
