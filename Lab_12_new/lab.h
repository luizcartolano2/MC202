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


node * Head;

void insert_node(int row, int col, int value);
void printa_tudo(node *List);
node *create_node(int row, int col, int value);

#endif
