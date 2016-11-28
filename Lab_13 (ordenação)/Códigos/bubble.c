#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble( int v[], int qtd );
#define MAX 3200000
#define REP 3
int main(int argc, char const *argv[]) {

  int i;
  int vet[MAX];
  clock_t start_time[REP], end_time[REP];
  printf("numero de elementos: %d\n",MAX);
  for(int k = 0; k < REP; k++){

    srand(42);

    for(i=0 ; i < MAX ; i++)
      vet[i] = rand();

    start_time[k] = clock();
    bubble(vet,MAX);
    end_time[k] = clock();

    printf("Iteration[%d] = %lf seconds\n",k,(((double)end_time[k] - (double)start_time[k]) / (double)CLOCKS_PER_SEC ));

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
