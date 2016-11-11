#ifndef csr
#define csr

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

#endif
