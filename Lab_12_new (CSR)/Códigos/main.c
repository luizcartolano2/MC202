//
//
//      created by Luiz Cartolano
//      ra 183012
//      program to implement a CSR matrix
//
//
#include "lab.h"

int main(int argc, char const *argv[]) {
  //variables declaration
  int k, i, max_row = 0, max_col = 0,row,col,val;
  Head = NULL;
  data *entradas;
  csr *CSR;

  //reading the number of nonzero elements in the CSR
  scanf("%d",&k);

  //dinamic allocation the array that will be use to read the entrys and the CSR
  entradas = calloc(k,sizeof(data));
  CSR = calloc(1,sizeof(csr));
  if((!entradas) || (!CSR))
    printf("Error in the allocation of the entrys struct or in the CSR struct\n");

  //loop to ready the entrys, insert nodes in the ordered list and find the number of rows and collums in the matrix
  for(i = 0; i < k; i++){
    scanf("%d %d %d",&(entradas[i]).line,&(entradas[i]).collum,&(entradas[i]).value);
    insert_node(entradas[i].line,entradas[i].collum,entradas[i].value);
    if(max_row < entradas[i].line)
      max_row = entradas[i].line;
    if(max_col < entradas[i].collum)
      max_col = entradas[i].collum;
  }
  free(entradas);

  //here we create the CSR representation
  CSR = create_csr(CSR,k,max_row);
  CSR->rows = max_row;
  CSR->cols = max_col;
  make_csr(Head,&CSR);

  //while loop to read the row and col and find it into the CSR matrix
  while (1) {
    scanf("%d %d",&row,&col);
    if((row == -1) && (col == -1))
      break;
    val = find_csr(CSR,row,col);
    printf("(%d,%d) = %d\n",row,col,val);
  }

  //free the list memory and the CSR matrix
  destruct_list(&Head);
  CSR = free_CSR(CSR);
  free(CSR);

  return 0;

}
