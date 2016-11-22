/*
  void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))

  base -- This is the pointer to the first element of the array to be sorted.
  nitems -- This is the number of elements in the array pointed by base.
  size -- This is the size in bytes of each element in the array.
  compar -- This is the function that compares two elements.

  example in how to use:
    int values[] = { 88, 56, 100, 2, 25 };
    int cmpfunc (const void * a, const void * b) {
     return ( *(int*)a - *(int*)b );
    }
    qsort(values, 5, sizeof(int), cmpfunc);

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  MAX 100000000
#define REP 1

int cmpfunc (const void * a, const void * b);

int main(int argc, char const *argv[]) {

  int i;
  int *vet;
  clock_t start_time[REP], end_time[REP];

  vet = malloc(MAX * sizeof(int));
  if(!vet)
    printf("FAILED\n");

  for(int k = 0; k < REP; k++){

    srand( (unsigned)time(NULL) );

    for(i=0 ; i < MAX ; i++)
      vet[i] = rand();

    start_time[k] = clock();
    qsort(vet,MAX,sizeof(int),cmpfunc);
    end_time[k] = clock();

    printf("Iteration[%d] = %lu seconds\n",k,((end_time[k] - start_time[k]) / CLOCKS_PER_SEC ));

  }

  return 0;

}


int cmpfunc (const void * a, const void * b) {

 return ( *(int*)a - *(int*)b );

}
