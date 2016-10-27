##include "lab03.h"

void insert(node **L,int pos,double element){

    int contador = 0;

    node *new = malloc(sizeof(node));
    new->value = element;

    if((*L) == NULL){
        new->A = NULL;
        new->B = NULL;
        (*L) = new;
        return;
    }
    if((*L)->B == NULL){
        new->B = NULL;
        new->A = (*L);
        (*L)->B = new;
        return;
    }

    node *ant = NULL, *actual = (*L);

    while(actual != NULL && contador < pos){
        ant = actual;
        if(actual->B != ant)
          actual = actual->B;
        else
          actual = actual->A;
        contador++;
    }

    if(actual == (*L)){
        if(actual->B != NULL){
          new->A = NULL;
          (*L)->A = new;
          new->B = (*L);
          (*L) = new;
        }else{
          new->A = NULL;
          (*L)->B = new;
          new->B = (*L);
          (*L) = new;
        }
    }else{
        if((actual->B != ant) && (actual->A != NULL)){
          new->B = ant->B;
          new->A = ant;
          ant->B = new;
          if(actual != NULL)
            actual->A = new;
          }else{
            new->B = ant->A;
            new->A = ant;
            ant->A = new;
            if(actual != NULL)
              actual->B = new;
          }
    }
    return;
}

void destruct(node **L){

    node *actual = (*L);
    node *ant = NULL;

    while(actual){
        node *aux = actual;
        if(actual->B != ant){
            ant = actual;
            actual = actual->B;
        }else{
            ant = actual;
            actual = actual->A;
        }
        free(aux);
    }
  //  free(*L);

   return;

}

void print_list(node **L){

  node *actual = (*L);
  node *ant = NULL;

  while(actual){
    printf("%.4lf ",(*L)->value);
    if(actual->B != ant){
      ant = actual;
      actual = actual->B;
    }else{
      ant = actual;
      actual = actual->A;
    }
  }
  printf("\n");
}

void revert(node **L, int pos1, int pos2){

  int contador = 0;
  node *actual = (*L), *actual2 = (*L);
  node *ant = NULL, *prox2 = NULL;

  while(contador < pos1){
    if(actual->B != ant){
        ant = actual;
        actual = actual->B;
    }else{
        ant = actual;
        actual = actual->A;
    }
  }
  contador = 0;
  while(contador < pos2){
    if(actual2->B != prox2){
        prox2 = actual2;
        actual2 = actual2->B;
    }else{
        prox2 = actual2;
        actual2 = actual2->A;
    }
  }
  //aqui iremos pegar o elemento que esta apos a 2 posicao requisitada, pra podermos modificar seus pointers
  if(actual2->B != prox2){
    prox2 = actual2->B;
  }else{
    prox2 = actual2->A;
  }
  if((ant != NULL) && (prox2 != NULL)){
      if(actual->A == ant)
        actual->A = prox2;
        else
          actual->B = prox2;
      if(ant->B == actual)
        ant->B = actual2;
        else
          ant->A = actual2;
      if(actual2->B == prox2)
        actual2->B = ant;
        else
          actual2->A = ant;
      if(prox2->A == actual2)
        prox2->A = actual;
        else
          prox2->B = actual;
      }
  if((ant == NULL) && (prox2 != NULL)){
      if(prox2->A == actual2)
        prox2->A = actual;
        else
          prox2->B = actual;

        if(actual->A == NULL)
          actual->A = prox2;
          else
            actual->B = prox2;

        if(actual2->B == prox2)
          actual2->B = NULL;
          else
            actual2->A = NULL;

        (*L) = actual2;
      }
  if((ant != NULL) && (prox2 == NULL)){
    if(ant->B  == actual)
      ant->B = actual2;
      else
        ant->A = actual2;

    if(actual->A == ant)
      actual->A = NULL;
      else
        actual->B = NULL;

    if(actual2->B == NULL)
      actual2->B = ant;
      else
      actual2->A = ant;
  }
  if((ant == NULL) && (prox2 == NULL)){
    (*L) = actual2;
  }
}
