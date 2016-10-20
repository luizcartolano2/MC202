#include "lab.h"

arv* arv_lib(arv *Arv){
  /*Funcao que libera a árvore em pós-ordem, isto é, primeiro verificamos se o no
  requisitado existe ou nao, caso ele exista chamamos a funcao para o filho da esquerda,
  assim, percorreremos todo o lado esquerdo da arvore, depois disso, percorreremos o lado direito
  e por fim liberamos o no principal*/

  if(Arv != NULL){
    arv_lib(Arv->left);
    arv_lib(Arv->right);
    free(Arv);
  }
  return NULL;
}

arv* create(){
  //funcao responsavel por criar um novo nó
  arv* new = malloc(sizeof(struct arv));
  new->right = NULL;
  new->left = NULL;
  new->p_right = 0;
  new->p_left = 0;

  return new;
}

arv* arv_build(char s){
  double peso;
  int no_value;
  char n_c;
  scanf("%c",&n_c);

  //caso base da função recursiva
  if(s == '(' && n_c == ')')
    return NULL;

  //criando o no da arvore
  arv *Arv = create();

  //chamamos a funcao recursivamente para o filho esquerdo (visto que a arvore esta dada em-ordem)
  Arv->left = arv_build(n_c);
  if(Arv->left != NULL){
      //leitura do peso da aresta
      scanf("%lf:",&peso);
      Arv->p_left = peso;
    }

  //leitura do valor do no
  scanf("%d",&no_value);
  Arv->data = no_value;

  //leitura do proximo caracter
  scanf("%c",&n_c);
  if(n_c == ':'){
    //se esse caracter for ":" sabemos que existe o peso a direita, e por isso devemos ler o peso do mesmo
    scanf("%lf",&peso);
    Arv->p_right = peso;
    scanf("%c",&n_c);
  }

  //aqui chamamos a funcao recursiva para o lado direito da arvore
  Arv->right = arv_build(n_c);

  scanf("%c",&n_c);

  return Arv;

}

double calc_peso(arv *Arv){
  double left, right;

  //se a arvore for nula, as arestas nao possuem peso, assim retornamos 0
  if(Arv == NULL)
    return 0;

    else if(Arv->left == NULL)
      return Arv->p_right + calc_peso(Arv->right);

      else if(Arv->right == NULL)
        return Arv->p_left + calc_peso(Arv->left);

          else{
            //aqui chamamos a funcao para cada um dos lados a fim de descobrir a soma dos pesos em cada um dos lados
            left = Arv->p_left + calc_peso(Arv->left);
            right = Arv->p_right + calc_peso(Arv->right);
            //aqui usamos o recurso de comparacao ternaria do c para retornamos o valor
            return (left >= right) ? left : right;
          }
}
