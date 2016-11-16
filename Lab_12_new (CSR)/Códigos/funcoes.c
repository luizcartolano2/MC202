//
//
//      created by Luiz Cartolano
//      ra 183012
//      program to implement a CSR matrix
//
//
#include "lab.h"

node *create_node(int row, int col, int value){
  //dinamic allcate the node and send a warning if it fails
  node *new_node = calloc(1,sizeof(node));
  if(!new_node)
    printf("Error in the allocation of a new_node\n");

  //initialise the values of the nodes with the users entrys
  new_node->row = row;
  new_node->col = col;
  new_node->val = value;
  new_node->next = NULL;

  return new_node;

}

void insert_node(int row, int col, int value){
  //here we call the create_node function
  node * cel = create_node(row,col,value);
  if(!cel)
    printf("Error to receive the node\n");

  //if the Head doesnt exist, it means we should inser the node in the beggining of the list
  if (!Head) {
    Head = cel;
    /*if the head exist, but the head row is bigger than the new_node node row, this one should
    be insert in the beggining of the list*/
  } else if (cel->row <= Head->row) {
      cel->next = Head;
      Head = cel;
    //if the first two conditions fail, it means we must search where to insert the new node
  } else {
      node *prev = Head;
      node *ant = NULL;
      //here is a while loop to find where to insert the new node
      while((prev) && (cel->row > prev->row)){
        ant = prev;
        prev = prev->next;
      }
      //if prev == NULL, it means we are ging to insert the node in the end of the list
      if (!prev) {
        ant->next = cel;
      }
      //if prev != NULL it means we are going to insert the node between two other nodes
      else {
        ant->next = cel;
        cel->next = prev;
      }
    }
}

void printa_tudo(node *List) {
  //here we have a while loop that print the list while list is not NULL
  while (List) {
    printf("line:%d col:%d val:%d\n",List->row,List->col,List->val);
    List = List->next;
  }
}

void destruct_list(node **L){
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

  //first we dinamic allocate the arrays of values, rows and cols
  Csr->val = calloc(size,sizeof(int));       /*A*/
  Csr->col_ind = calloc(size,sizeof(int));   /*C*/
  Csr->row_ptr = calloc(rows+1,sizeof(int)); /*R*/
  if((!Csr->val) || (!Csr->col_ind) || (!Csr->row_ptr))
    printf("Error in the CSR allocation\n");

  //here we initialise some importants variables, like the number of nonzero values and rows in the matrix
  Csr->val_length = size;
  Csr->row_ptr_length = rows + 1;

  //here we initialise the row_ptr array (R) with '-1' to mark he as free to insert values
  for(i = 0; i < Csr->row_ptr_length; i++)
    Csr->row_ptr[i] = -1;

  return Csr;
}

void make_csr(node *list, csr **Crs){
  node *aux = Head;
  //counters declaration
  int i = 0, k;

  //the loop exists while the list it's not NULL, what means we run the entire list
  while (aux) {
    //put the nonzero values in the array
    (*Crs)->val[i] = aux->val;            /*A*/
    //put the col values in the array
    (*Crs)->col_ind[i] = aux->col;        /*C*/
    //if the row_ptr position is free to be use we put the counter value in the array
    if ((*Crs)->row_ptr[aux->row] == -1)
      (*Crs)->row_ptr[aux->row] = i;      /*R*/
    aux = aux->next;
    i++;
  }
  /*here we put important marks in the row_ptr array, the first element (i = 0) is always zero
  and the last element (i = row+1) is always equal to the number of nonzero values*/
  (*Crs)->row_ptr[0] = 0;
  (*Crs)->row_ptr[(*Crs)->row_ptr_length] = (*Crs)->val_length;

  //here we have a loop to fill the blanks of the non exists rows  
  for(k = (*Crs)->row_ptr_length; k > 0; k--)
    if ((*Crs)->row_ptr[k] == -1)
      (*Crs)->row_ptr[k] = (*Crs)->row_ptr[k+1];

}

int find_csr(csr *Csr, int row, int col){
  int i;

  /*here we have a condition that make the work easy, if the (row,col)
  asked by the user is bigger than the (row,col) of the matrix, the ellement
  doesnt exist, so we return 0 */
  if ((row > Csr->rows) || (col > Csr->cols)) {
    return 0;
  }
  //if the the (row,col) could exist we have to check it into the representation
  else {
    /*the for loop use the fact that the difference between the value in the row_ptr[row] and row_ptr[row+1]
    is the number of nonzero elements in this row*/
    for(i = Csr->row_ptr[row];i < Csr->row_ptr[row+1]; i++)
      //if the col in the csr is the same col asked by the user we return the val, else we return zero
      if(Csr->col_ind[i] == col)
        return Csr->val[i];
  }

  return 0;

}

csr *free_CSR(csr *CSR){
  //here we free the three CSR arrays
  free(CSR->val);
  free(CSR->col_ind);
  free(CSR->row_ptr);

  return CSR;

}
