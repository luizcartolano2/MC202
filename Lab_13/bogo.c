#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 16
#define REP 3

bool is_sorted(int *a, int n);
void shuffle(int *a, int n);
void bogosort(int *a, int n);

int main(int argc, char const *argv[]) {

  int i;
  int *vet;
  clock_t start_time[REP], end_time[REP];

  vet = malloc(MAX * sizeof(int));
  if(!vet)
    printf("FAILED\n");

  printf("numero de elementos:%d\n",MAX);
  for(int k = 0; k < REP; k++){

    srand(42);

    for(i=0 ; i < MAX ; i++)
      vet[i] = rand();

    start_time[k] = clock();
    bogosort(vet,MAX);
    end_time[k] = clock();

    printf("Iteration[%d] = %lf seconds\n",k,(((double)end_time[k] - (double)start_time[k]) / (double)CLOCKS_PER_SEC ));

  }

  return 0;

}

bool is_sorted(int *a, int n) {
  while ( --n >= 1 ) {
    if ( a[n] < a[n-1] ) return false;
  }
  return true;
}

void shuffle(int *a, int n) {
  int i, t, r;
  for(i=0; i < n; i++) {
    t = a[i];
    r = rand() % n;
    a[i] = a[r];
    a[r] = t;
  }
}

void bogosort(int *a, int n) {
  while (!is_sorted(a,n))
    shuffle(a, n);
}
