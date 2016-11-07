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
  heap *Heap = NULL, aux;
  tamanho_heap = 0;

  if(!Heap)
      Heap = create_heap();
      
  do{
    scanf("%c",&command);
    switch (command){
      case 'i':
        scanf("%d %d",&key,&cost);
        h_insert(Heap,key,cost,&tamanho_heap);
        break;

      case 'm':
        if(!tamanho_heap)
          printf("vazio\n");
        else{
          aux = h_remove(Heap,&tamanho_heap);
          printf("minimo {%d,%d}\n",aux.chave,aux.custo);
        }
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
