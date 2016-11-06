//
//
//    Created by Luiz Cartolano
//    RA: 183012
//    Program to implement a minimun heap in C
//
//

#include "lab.h"

int main(int argc, char const *argv[]){

  char command;
  int key, cost;
  heap *Heap = NULL;
  tamanho_heap = 0;

  do{
    scanf("%c",&command);
    switch (command){
      case 'i':
        if(!Heap)
            Heap = create_heap();

        scanf("%d %d",&key,&cost);
        h_insert(Heap,key,cost,&tamanho_heap);

        break;
      case 'm':
        break;
      case 'd':
        scanf("%d %d",&key,&cost);
        break;
      case 't':
        break;
    }
  }while (command != 't');

  return 0;

}
