#include "lab.h"

/**
 * create node to be insert in the list
 *
 * @param int row
 * @param int col
 * @param int value
 *
 * @return node with the param informations
 */
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

/**
 * insert a new node in the list
 *
 * @param int row
 * @param int col
 * @param int value
 *
 * @return the function doesnt have a return
 */
void insert_node(int row, int col, int value){

  node * cel = create_node(row,col,value);
  if(!cel)
    printf("Error to receive the node\n");

  if (!Head) {
    Head = cel;
    //printf("!Head\n");
  } else if (cel->row <= Head->row) {
      cel->next = Head;
      Head = cel;
      //printf("cel->row <= Head->row\n");
  } else {
      node *prev = Head;
      node *ant = NULL;
      //printf("else\n");
      while((prev != NULL) && (cel->row > prev->row)){
        //printf("caralho porra\n");
        ant = prev;
        prev = prev->next;
        //if(!prev)
          //printf("pruuuuuuuuuuuuuuuuuuuu\n");
        //printf("while((cel->row > prev->row))\n");
      }
      //printf("!prev\n");
      if (!prev) {
        ant->next = cel;
        //printf("!prev\n");
      } else {
        ant->next = cel;
        cel->next = prev;
        //printf("else2\n");
      }
    }
}

/**
 * function to print the list
 *
 * @param node *List
 *
 * @return the function doesnt have a return
 */
void printa_tudo(node *List) {
  while (List) {
    printf("line:%d col:%d val:%d\n",List->row,List->col,List->val);
    List = List->next;
  }
}

/**
 * destruct the list
 *
 * @param node **L
 *
 * @return the function doesnt have a return
 */
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

/**
 * create the CSR matrix with important informations
 *
 * @param csr *Csr
 * @param int size - number of nonzero elements
 * @param int rows - number of rows in the matrix
 *
 * @return CSR matrix with arrays allocated and initialised
 */
csr *create_csr(csr *Csr, int size, int rows){
  int i;

  Csr->val = calloc(size,sizeof(int));       /*A*/
  Csr->col_ind = calloc(size,sizeof(int));   /*C*/
  Csr->row_ptr = calloc(rows+1,sizeof(int)); /*R*/
  if((!Csr->val) || (!Csr->col_ind) || (!Csr->row_ptr))
    printf("Error in the CSR allocation\n");

  Csr->val_length = size;
  Csr->row_ptr_length = rows + 1;

  for(i = 0; i < Csr->row_ptr_length; i++)
    Csr->row_ptr[i] = -1;

  return Csr;
}

/**
 * construct the CSR matrix based on the coordinated list already created
 *
 * @param csr *Csr
 * @param int size - number of nonzero elements
 * @param int rows - number of rows in the matrix
 *
 * @return the function doesnt have a return, but in his end the CSR matrix will be their with arrays allocated and initialised
 */
void make_csr(node *list, csr **Crs){
  node *aux = Head;
  int i = 0, k;

  while (aux) {
    (*Crs)->val[i] = aux->val;            /*A*/
    (*Crs)->col_ind[i] = aux->col;        /*C*/
    if ((*Crs)->row_ptr[aux->row] == -1)
      (*Crs)->row_ptr[aux->row] = i;      /*R*/
    aux = aux->next;
    i++;
  }
  (*Crs)->row_ptr[0] = 0;
  (*Crs)->row_ptr[(*Crs)->row_ptr_length] = (*Crs)->val_length;

  for(k = (*Crs)->row_ptr_length; k > 0; k--)
    if ((*Crs)->row_ptr[k] == -1)
      (*Crs)->row_ptr[k] = (*Crs)->row_ptr[k+1];

}

/**
 * find a value in the CSR matrix
 *
 * @param csr *Csr
 * @param int row - row asked by the user
 * @param int col - col asked by the user
 *
 * @return the value of the (row,col) asked by the user, if it exist or zero if it doesnt
 */
int find_csr(csr *Csr, int row, int col){
  int i;

  if ((row > Csr->rows) || (col > Csr->cols)) {
    return 0;
  } else {
      for(i = Csr->row_ptr[row];i < Csr->row_ptr[row+1]; i++)
        if(Csr->col_ind[i] == col)
          return Csr->val[i];
  }

  return 0;

}

/**
 * free the CSR matrix
 *
 * @param csr *Csr
 *
 * @return the CSR with all the arrays free
 */
csr *free_CSR(csr *CSR){
  free(CSR->val);
  free(CSR->col_ind);
  free(CSR->row_ptr);

  return CSR;

}

/**
 * print the values inside the CSR arrays
 *
 * @param csr *Csr
 *
 * @return the function doesnt have a return
 */
void print_CSR(csr *CSR){
  int i;
  for(i = 0; i < CSR->row_ptr_length+1;i++)
    printf("row_ptr[%d]=%d\n",i,CSR->row_ptr[i]);

  for(i = 0; i < CSR->cols; i++)
    printf("col_ind[%d]=%d\n",i,CSR->col_ind[i]);

  for(i = 0; i < CSR->val_length; i++)
    printf("val[%d]=%d\n",i,CSR->val[i]);
}
