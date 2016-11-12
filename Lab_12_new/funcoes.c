#include "lab.h"

node *create_node(int row, int col, int value){
  node *new_node = calloc(1,sizeof(node));
  if(!new_node)
    printf("Error in the allocation of a new_node\n");

  new_node->row = row;
  new_node->col = col;
  new_node->val = value;
  new_node->next = NULL;

  return new_node;

}

void insert_node(int row, int col, int value){

  node * cel = create_node(row,col,value);
  if(!cel)
    printf("Error to receive the node\n");

  if (!Head) {
    Head = cel;
  } else if (cel->row <= Head->row) {
    cel->next = Head;
    Head = cel;
  } else {
    node *prev = Head;
    node *ant = NULL;
    while((cel->row > prev->row)){
      ant = prev;
      prev = prev->next;
    }
    if (!prev) {
      ant->next = cel;
    } else {
      ant->next = cel;
      cel->next = prev;
    }
  }
}

void printa_tudo(node *List) {
  while (List) {
    printf("line:%d col:%d val:%d\n",List->row,List->col,List->val);
    List = List->next;
  }
}

void destruct_list(node** L){
  //here while the head exist whe free the aux apointer

  while(*L){
    node* aux = (*L);
    (*L) = aux->next;
    free(aux);
  }
  free(*L);
  (*L) = NULL;
}

csr *create_csr(csr *Csr, int size, int rows){
  int i;

  Csr->val = calloc(size,sizeof(int));
  Csr->col_ind = calloc(size,sizeof(int));
  Csr->row_ptr = calloc(rows+1,sizeof(int));
  if((!Csr->val) || (!Csr->col_ind) || (!Csr->row_ptr))
    printf("Error in the CSR allocation\n");

  Csr->val_length = size;
  Csr->row_ptr_length = rows + 1;

  for(i = 0; i < Csr->row_ptr_length; i++)
    Csr->row_ptr[i] = -1;

  return Csr;
}

void make_csr(node *list, csr **Crs){
  node *aux = Head;
  int i = 0, k;

  while (aux) {
    (*Crs)->val[i] = aux->val;
    (*Crs)->col_ind[i] = aux->col;
    if ((*Crs)->row_ptr[aux->row] == -1)
      (*Crs)->row_ptr[aux->row] = i;
    aux = aux->next;
    i++;
  }
  (*Crs)->row_ptr[0] = 0;
  (*Crs)->row_ptr[(*Crs)->row_ptr_length-1] = (*Crs)->val_length;

  for(k = (*Crs)->row_ptr_length - 1; k > 0; k--)
    if ((*Crs)->row_ptr[k] == -1)
      (*Crs)->row_ptr[k] = (*Crs)->row_ptr[k+1];

}


int find_csr(csr *Csr, int row, int col){
  int i;

  for(i = Csr->row_ptr[row];i < Csr->row_ptr[row]; i++)
    if(Csr->col_ind[i] == col)
      return Csr->val[i];

  return 0;

}

csr *free_CSR(csr *CSR){
  free(CSR->val);
  free(CSR->col_ind);
  free(CSR->row_ptr);

  return CSR;

}

void print_CSR(csr *CSR){
  int i;
  for(i = 0; i < CSR->row_ptr_length+1;i++)
    printf("row_ptr[%d]=%d\n",i,CSR->row_ptr[i]);

  for(i = 0; i < CSR->cols; i++)
    printf("col_ind[%d]=%d\n",i,CSR->col_ind[i]);

  for(i = 0; i < CSR->val_length; i++)
    printf("val[%d]=%d\n",i,CSR->val[i]);
}
