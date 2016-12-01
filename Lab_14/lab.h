#ifndef lab
#define  lab

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int vert;
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
 * @param int ***graf
 * @param int vert_i
 * @param int vert_j
 *
 * @return the function has no return
 */
 node* insertList(node *graf, int vert_i, int vert_j);
 void Print(node *graf, int size);

#endif
