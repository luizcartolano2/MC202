#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 78570000
#define REP 3

void shell_sort(int *a, int size);
void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main(int argc, char const *argv[]) {

  int i;
  int *vet;
  clock_t start_time[REP], end_time[REP];

  vet = malloc(MAX * sizeof(int));
  if(!vet)
    printf("FAILED\n");

  printf("numero de elementos:%d\n",MAX);
  for(int k = 0; k < REP; k++){

    srand( (unsigned)time(NULL) );

    for(i=0 ; i < MAX ; i++)
      vet[i] = rand();

    start_time[k] = clock();
    shell_sort(vet,MAX);
    end_time[k] = clock();

    printf("Iteration[%d] = %lf seconds\n",k,(((double)end_time[k] - (double)start_time[k]) / (double)CLOCKS_PER_SEC ));
  }

  return 0;
}

void shell_sort(int *a, int size) {
 int i , j , value;
 int gap = 1;

 do {
  gap = 3*gap+1;
 } while(gap < size);

 do {
  gap /= 3;
  for(i = gap; i < size; i++) {
   value = a[i];
   j = i - gap;

   while (j >= 0 && value < a[j]) {
    a[j + gap] = a[j];
    j -= gap;
   }
   a[j + gap] = value;
  }
 }while(gap > 1);
}
