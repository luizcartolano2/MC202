#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 90000000
#define REP 3

void Merge(int *A,int *L,int leftCount,int *R,int rightCount);
void MergeSort(int *A,int n);
void printArray(int A[], int size);

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

    int arr_size = sizeof(vet)/sizeof(vet[0]);

    start_time[k] = clock();
    MergeSort(vet,MAX);
    end_time[k] = clock();

    printf("Iteration[%d] = %lf seconds\n",k,(((double)end_time[k] - (double)start_time[k]) / (double)CLOCKS_PER_SEC ));

  }


  return 0;

}
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j])
      A[k++] = L[i++];
		else
      A[k++] = R[j++];
	}
	while(i < leftCount)
    A[k++] = L[i++];

  while(j < rightCount)
    A[k++] = R[j++];
}

// Recursive function to sort an array of integers.
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2)
    return; // base condition. If the array has less than two element, do nothing.

	mid = n/2;  // find the mid index.

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++)
    L[i] = A[i]; // creating left subarray

  for(i = mid;i<n;i++)
    R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
  free(L);
  free(R);
}


void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
