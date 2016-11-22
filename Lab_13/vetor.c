/*Program to create vector that will be used in other Program*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  MAX 3

int main(int argc, char const *argv[]) {

  int i;
  srand( (unsigned)time(NULL) );

  for(i=1 ; i <= MAX ; i++)
    if(i == 1)
      printf("[%d,",rand());

    else if(i == MAX)
      printf("%d]\n",rand());

    else
      printf("%d,",rand());
  return 0;

}
