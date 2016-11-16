#ifndef lab
#define lab

#include <stdio.h>
#include <stdlib.h>

//declaration of node struct
typedef struct node {
	int row, col, val;
	struct node *next;
}node;

//declaration of the struct that will be used to read the entrys
typedef struct data{
  int line;
  int collum;
  int value;
}data;

//declaration of the CSR struct, it's make easy to work with them in the future
typedef struct CSR{
  int *val;
	int *col_ind;
	int *row_ptr;
	int val_length;
	int row_ptr_length;
	int rows;
	int cols;
}csr;

//global declaration of the list head
node * Head;

//functions to mannage the list
/**
 * create node to be insert in the list
 *
 * @param int row
 * @param int col
 * @param int value
 *
 * @return node with the param informations
 */
node *create_node(int row, int col, int value);

/**
 * insert a new node in the list
 *
 * @param int row
 * @param int col
 * @param int value
 *
 * @return the function doesnt have a return
 */
void insert_node(int row, int col, int value);

/**
 * function to print the list
 *
 * @param node *List
 *
 * @return the function doesnt have a return
 */
void printa_tudo(node *List);

/**
 * destruct the list
 *
 * @param node **L
 *
 * @return the function doesnt have a return
 */
void destruct_list(node** L);

//functions to mannage the CSR
/**
 * create the CSR matrix with important informations
 *
 * @param csr *Csr
 * @param int size - number of nonzero elements
 * @param int rows - number of rows in the matrix
 *
 * @return CSR matrix with arrays allocated and initialised
 */

 /**
  * construct the CSR matrix based on the coordinated list already created
  *
  * @param csr *Csr
  * @param int size - number of nonzero elements
  * @param int rows - number of rows in the matrix
  *
  * @return the function doesnt have a return, but in his end the CSR matrix will be their with arrays allocated and initialised
  */
csr *create_csr(csr *Csr, int size, int rows);

/**
 * find a value in the CSR matrix
 *
 * @param csr *Csr
 * @param int row - row asked by the user
 * @param int col - col asked by the user
 *
 * @return the value of the (row,col) asked by the user, if it exist or zero if it doesnt
 */
int find_csr(csr *Csr, int row, int col);

/**
 * free the CSR matrix
 *
 * @param csr *Csr
 *
 * @return the CSR with all the arrays free
 */
csr *free_CSR(csr *CSR);

/**
 * print the values inside the CSR arrays
 *
 * @param csr *Csr
 *
 * @return the function doesnt have a return
 */
void print_CSR(csr *CSR);

#endif /*lab*/
