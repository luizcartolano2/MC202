//
//
//  Created by Luiz Eduardo Cartolano
//  RA: 183012
//
//

#include "lab05.h"

int main(void){

  char option[30];
  unsigned char *array = NULL;
  int teste,k,j,i,count = 0,aux;

  n_elements = 0;

  //loop que chama as funcoes enquanto a opcao escolhida nao for "exit"
  do{
    //leitura da opcao que devera ser executada
    inicio: scanf("%s",option);
    if(strcmp(option,"create") == 0){
      create(&array);
    }
    if(strcmp(option,"add") == 0){
      add(&array);
    }
    if(strcmp(option,"remove") == 0){
      remov(&array);
    }
    if(strcmp(option,"in") == 0){

      scanf("%d",&k);
      teste = in(&array,k);

      if(teste == 1){
        printf("belongs(%d) = true\n",k);
      }else{
        printf("belongs(%d) = false\n",k);
      }
    }
    if(strcmp(option,"rank") == 0){
      scanf("%d",&k);
      if(k <= n){
        teste = rank(&array,k);
        printf("rank(%d) = %d\n",k,teste);
      }
    }
    if(strcmp(option,"select") == 0){
      scanf("%d",&k);
      if(k <= n_elements){
        teste = sele(&array,k);
        printf("select(%d) = %d\n",k,teste);
      }else{
        printf("select(%d) = 0\n",k);
      }
    }
    if(strcmp(option,"rangecount") == 0){
      scanf("%d%d",&j,&k);
      teste = rangecount(&array,j,k);
      printf("rangecount(%d,%d) = %d\n",j,k,teste);
    }
    if(strcmp(option,"print") == 0){
      print(&array);
    }
  }while(strcmp(option,"exit") != 0);

  free(array);

  return 0;

}
