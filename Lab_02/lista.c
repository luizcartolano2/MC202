#include "lista.h"

int main(void){

  int n_list, n_reg, reg;
  node *list1 = NULL, *list2 = NULL, *list3 = NULL;
  int i;
  int count_mtf = 0, count_trans = 0, count_count = 0;

  scanf("%d",&n_list);
  scanf("%d",&n_reg);

  //here we call the function that inserct the nodes
  for(i = n_list; i > 0; i--){
    insert(&list1,i);
    insert(&list2,i);
    insert(&list3,i);
  }

  //here we call the functions that changes postitions and calc the cost of this operation
  for(i = 0; i < n_reg; i++){
    scanf("%d",&reg);
    count_mtf = count_mtf + move_to_front(&list1,reg);
    count_trans = count_trans + transpose(&list2,reg);
    count_count = count_count + counter(&list3,reg);
  }

  printf("%d %d %d\n",count_mtf,count_trans,count_count);

  //here we freddom the memory
  destruct(&list1);
  destruct(&list2);
  destruct(&list3);

  return 0;

}


void insert(node** L, int element){
  //here we dinamic alocate the node and make the head pointer apoint to the new node

  node* new = malloc(sizeof(node));

  new->next = (*L);
  (*L) = new;
  new->value = element;
}

void destruct(node** L){
  //here while the head exist whe free the aux apointer

  while(*L){
    node* aux = (*L);
    (*L) = aux->next;
    free(aux);
  }
  free(*L);
  (*L) = NULL;
}

int move_to_front(node** L, int number){
  //here we use auxiliars to free the memory of one register without lose the rest of the list and, together we add an element in the begining of the list

  int contador = 0;
  node* actual = (*L);
  node* ant = NULL;

  while (1){

    if((*L)->value == number){
      contador++;
      break;
    }

    else{
      contador++;
      if(actual->value == number){
        ant->next = actual->next;
        free(actual);
        insert(L,number);
        break;
      }
      ant = actual;
      actual = actual->next;
    }
  }

  return contador;

}

int transpose(node** L, int number){
  //here we use auxiliars pointer to change the posiction of two nodes
  /*if it's not the first or the second node we make the previous element apoint to where the actual
  apointer is apointing and then we make tha actual apointer apoint to the previous element whe make
  the previous element of the previous element apointer to the actual one*/

  int contador = 0;
  node* actual = (*L);
  node* ant = NULL;
  node* aux = NULL;

  if(actual->value == number){
    contador++;
  }
    else{
    while (1) {
      contador++;
      if((actual)&&(ant)&&(aux == NULL)&&(actual->value == number)){
        (*L) = actual;
        ant->next = actual->next;
        actual->next = ant;
        break;
      }
      if(actual->value == number){
        ant->next = actual->next;
        actual->next = ant;
        aux->next = actual;
        break;
      }
        aux = ant;
        ant = actual;
        actual = actual->next;
    }
  }

  return contador;

}

node* find_value(node** L, int number, int* contador){
  //here we use an apointer to find the value, and then we return the previous one

  (*contador) = 0;
  node* aux = (*L);
  node* ant = NULL;

  while(1){
    (*contador)++;
    if(aux->value == number){
      aux->count++;
      return ant;
    }
    ant = aux;
    aux = aux->next;
  }
  //return 666;
}

int counter(node** L, int number){
  /*firts we call the function find value and get a pointer to the previous element of the one we search
  . After it, we use other three pointer to change the node position to a position where his counter is less
  or equal to the others one (we use some conditionals for it)*/

  int contador = 0;
  node* ant = find_value(L,number,&contador);

  if(ant == NULL){
    return contador;
  }

  node* actual = ant->next;

  //if the element is the first one we just return the counter
  if(ant->count > actual->count){
    return contador;
  }

  node* aux1 = (*L);
  node* aux2 = NULL;

  //else we find the first position where the counter is no longer bigger than the counter of our element
  //we just use some conditionals to know the position of it and don't try to acess wrong memory
  while(aux1->count > actual->count){
    aux2 = aux1;
    aux1 = aux1->next;
  }

  if(aux2==NULL){
    ant->next = actual->next;
    (*L)= actual;
    actual->next = aux1;
  }
  else{
    ant->next = actual->next;
    aux2->next = actual;
    actual->next = aux1;
  }

  return contador;

}
