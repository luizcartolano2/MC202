#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define MAX 258570000
#define REP 3

int cmpfunc (const void * a, const void * b);

int main(int argc, char const *argv[]) {

  int i;
  int *vet;
  clock_t start_time[REP], end_time[REP];
  int MAX;

  scanf("%d",&MAX);

  vet = malloc(MAX * sizeof(int));
  if(!vet)
    printf("FAILED\n");

  printf("numero de elementos:%d\n",MAX);
  for(int k = 0; k < REP; k++){

    srand( (unsigned)time(NULL) );

    for(i=0 ; i < MAX ; i++)
      vet[i] = rand();

    start_time[k] = clock();
    qsort(vet,MAX,sizeof(int),cmpfunc);
    end_time[k] = clock();

    printf("Iteration[%d] = %lf seconds\n",k,(((double)end_time[k] - (double)start_time[k]) / (double)CLOCKS_PER_SEC ));

  }

  return 0;

}


int cmpfunc (const void * a, const void * b) {

 return ( *(int*)a - *(int*)b );

}
