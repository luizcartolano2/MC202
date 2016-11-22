#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//call the function sort inside the main, declare the vectors as global
//declarar um vetor vazio de mesmo tamanho
//parametros de sort (0,num_max_ele)
void merging(int low, int mid, int high);
void sort(int low, int high);

int main(int argc, char const *argv[]) {
  /* code */
  return 0;

}

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }

   while(l1 <= mid)
      b[i++] = a[l1++];

   while(l2 <= high)
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else {
      return;
   }
}
