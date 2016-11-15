#ifndef Vaporeon
#define Vaporeon

  #include<stdio.h>
  #include<stdlib.h>

  //struct of the nodes
  typedef struct node{
      int value;
      int count;
      struct node* next;
    }node;

  //function that inserct a node in the begning of a list
  void insert(node** L,int element);

  //function that destruct the entire list
  void destruct(node** L);

  //function that move the register to the first position of the list
  int move_to_front(node** L, int number);

  //function that change the position of the register with the precedent register
  int transpose(node** L, int number);

  //function that find the register given in the list
  node* find_value(node** L, int number, int* contador);

  //function that change the positon of the register according to the counter 
  int counter(node** L, int number);

#endif /* lista.h */
