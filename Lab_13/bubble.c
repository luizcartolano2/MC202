/*
    clock_t start_time, end_time;

    start_time = clock();

    compute();
    end_time = clock();
    printf( "Execution time was %lu seconds\n",
          (end_time - start_time) / CLOCKS_PER_SEC );
  }
  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble( int v[], int qtd );
#define  MAX 100000
#define REP 5
int main(int argc, char const *argv[]) {

  int i;
  int vet[MAX];
  clock_t start_time[REP], end_time[REP];

  for(int k = 0; k < REP; k++){

    srand( (unsigned)time(NULL) );

    for(i=0 ; i < MAX ; i++)
      vet[i] = rand();

    start_time[k] = clock();
    bubble(vet,MAX);
    end_time[k] = clock();

    printf("Iteration[%d] = %lu seconds\n",k,((end_time[k] - start_time[k]) / CLOCKS_PER_SEC ));

  }

  return 0;

}

void bubble( int v[], int qtd ){

  int i;
  int j;
  int aux;
  int k = qtd - 1 ;

  for(i = 0; i < qtd; i++)
  {
     for(j = 0; j < k; j++)
     {
        if(v[j] > v[j+1])
        {
            aux = v[j];
        v[j] = v[j+1];
        v[j+1]=aux;
        }
     }
     k--;
  }
}
