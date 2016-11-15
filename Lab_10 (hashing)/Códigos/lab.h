#ifndef lab_10
#define  lab_10

#define M 65521

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  long long int key;
  int value;
}table;

//functions
int hash_index(long long int key);
int hash_index2(long long int key);
void init_table(table Table[]);
int hash_insert(table Table[],long long int key, int value);
int hash_search(table Table[],long long int key);
void hash_remove(table Table[],long long int key);

#endif
