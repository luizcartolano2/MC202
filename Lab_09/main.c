#include "lab.h"

int main(void){

  //definindo as variaveis
  arv *Arv = NULL; /*raiz da arvore*/
  double weight = 0; /*variavel que recebera o somatorio dos pesos*/
  char s;

  while (scanf("%c",&s) != EOF){
    //scanf("%c",&s);
    //chama a funcao que constroi a arvore
    Arv = arv_build(Arv,s);

    //chama a funcao que calcula o peso das arestas
    weight = calc_peso(Arv);

    //chama a funcao que libera a arvore
    Arv = arv_lib(Arv);

    //printa a saida
    printf("%.3lf\n",weight);

    scanf("%c",&s);

  }

  return 0;

}
