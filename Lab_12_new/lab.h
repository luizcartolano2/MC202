#ifndef lab
#define lab

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int row, col, val;
	struct node *next;
}node;

typedef struct data{
  int line;
  int collum;
  int value;
}data;

typedef struct CSR{
  int *val;
	int *col_ind;
	int *row_ptr;
	int val_length;
	int row_ptr_length;
	int rows;
	int cols;
}csr;

//global the declaration of the list head
node * Head;

//functions to mannage the list
void insert_node(int row, int col, int value);
void printa_tudo(node *List);
node *create_node(int row, int col, int value);
void destruct_list(node** L);

//functions to mannage the CSR
void make_csr(node *list, csr *Crs);
csr *create_csr(csr *Csr, int size, int rows);
int find_csr(csr *Csr, int row, int col);
csr *free_CSR(csr *CSR);

#endif
