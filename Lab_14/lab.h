#ifndef lab
#define  lab

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int vert;
  int color;  //0 - white, 1 - grey, 2 - black
  int d,f;
  struct node *next;
}node;
//functions that will mannage with the Adjacency List
/**
 * create node to be insert in the list
 *
 * @param int vert
 *
 * @return node with the param informations
 */
node *create_node(int vert);

/**
 * insert the node into the Adjacency List
 *
 * @param node *graf
 * @param int vert_i
 * @param int vert_j
 *
 * @return the function a pointer to the begining of the list
 */
 node* insertList(node *graf, int vert_i, int vert_j);

 void Print(node *graf, int size);

#endif
