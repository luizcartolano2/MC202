#include "lab.h"

int main(int argc, char const *argv[]){

  char command;
  int key, cost;

  do{
    scanf("%c",&command);
    switch (command){
      case 'i':
        scanf("%d %d",&key,&cost);
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
