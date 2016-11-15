//
//
//    Created by Luiz Cartolano
//    RA: 183012
//
//
#include"lab.h"

int main(void){

  char ordem[53],pre[53];
  int ordemIn = 0, ordemFim, height, i;
  arv *Arv = NULL;

  while(scanf("%s",pre) != EOF){
    scanf("%s",ordem);
    ordemFim = strlen(ordem);
    preIndice = 0;
    Arv = arv_build(ordem,pre,ordemIn,ordemFim - 1);
    height = arv_print(Arv);
    printf(" ");
    for(i = 1; i <= height + 1; i++){
      arv_size(Arv,i);
    }
    printf("\n");
    Arv = arv_lib(Arv);
  }

  return 0;

}
