//
//
//    Created by Luiz Cartolano
//    RA: 183012
//
//
#include"lab.h"

int main(void){

  char ordem[52],pre[52];
  int ordemIn = 0, ordemFim;
  arv *Arv = NULL;


  while(scanf("%s",pre) != EOF){
    scanf("%s",ordem);
    ordemFim = strlen(ordem);
    preIndice = 0;
    Arv = arv_build(ordem,pre,ordemIn,ordemFim - 1);
    arv_print(Arv);
    printf("\n");
    Arv = arv_lib(Arv);
  }

  return 0;

}
