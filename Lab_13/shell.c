#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int *a, int size);

int main(int argc, char const *argv[]) {
  /* code */
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
