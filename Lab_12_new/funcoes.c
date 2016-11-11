#include "lab.h"

node *create_node(int row, int col, int value){
  node *new_node = calloc(1,sizeof(node));
  if(!new_node)
    printf("memória insuficiente para alocar um novo nó\n");

  new_node->row = row;
  new_node->col = col;
  new_node->val = value;
  new_node->next = NULL;

  return new_node;

}

void insert_node(int row, int col, int value){

  node * cel = create_node(row,col,value);
  if(!cel)
    printf("erro ao receber o retorno de insert_node\n");

  if (!Head) {
    Head = cel;
    printf("!Head\n");
  } else if (cel->row <= Head->row) {
    cel->next = Head;
    Head = cel;
    printf("cel->row <= Head->row\n");
  } else {
    node *prev = Head;
    node *ant = NULL;
    printf("else\n");
    while((cel->row > prev->row)){
      printf("ant = prev:\n");
      ant = prev;
      printf("prev = prev->next\n");
      prev = prev->next;
    }
    if (!prev) {
      ant->next = cel;
      printf("!prev\n");
    } else {
      ant->next = cel;
      cel->next = prev;
      printf("else2\n");
    }
  }
}

void printa_tudo(node *List) {
  while (List) {
    printf("line:%d col:%d val:%d\n",List->row,List->col,List->val);
    List = List->next;
  }
}
