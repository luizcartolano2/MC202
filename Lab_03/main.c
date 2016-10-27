//
//
//  Created by Luiz Eduardo Cartolano on 07/09/16.
//  RA: 183012
//
//

#include "lab03.h"

int main(void){

  char operation;
  double entry;
  int pos, pos1, pos2;
  node *list = NULL;

  do{
    scanf("%c",&operation);
    switch (operation) {
      case 'i':
        scanf("%d %lf",&pos,&entry);
        insert(&list,pos,entry);
        break;
      case 'p':
        print_list(&list);
        break;
      case 'v':
        scanf("%d %d",&pos1,&pos2);
        if(pos1 < pos2)
          revert(&list,pos1,pos2);
        else
          revert(&list,pos2,pos1);
        break;
      case 't':
        break;
    }
  }while (operation != 't');

  //aqui chamamos a funcao que libera a memoria da lista
  destruct(&list);

  return 0;

}
