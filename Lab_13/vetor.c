/*Program to create vector that will be used in other Program*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {

  int i;
  printf("intervalo da rand: [0,%d]\n", RAND_MAX);
  srand( (unsigned)time(NULL) );

  //MUDAR O i para obter o número de elementos do vetor q vc quer
  for(i=1 ; i <= 10 ; i++)
      printf("Numero %d: %d\n",i, rand());

  return 0;

}
