//
//
//      created by Luiz Cartolano
//      RA: 183012
//
//
#ifndef lab
#define  lab

#include <stdio.h>
#include <stdlib.h>

int tim3;
int ciclica;
int *ped;
int ped_i;

typedef struct gpt {
  struct node * no;
  struct gpt *next;
}gpt;

typedef struct node {
  int vert;
  int color;  //0 - white, 1 - grey, 2 - black
  int ti,tf;
  gpt *list;
}node;

/**
 * insert the node into the Adjacency List
 *
 * @param node *graph
 * @param int i
 * @param int j
 *
 * @return the function a pointer to the begining of the list
 */
void insertList(node *graph, int i, int j);
/**
 * function DFS
 *
 * @param node *graph
 * @param int size
 *
 * @return the function has no return
 */
void DFS(node *graph, int size);
/**
 * function DFS_Visit
 *
 * @param node *graph
 * @param int i
 * @param int size
 *
 * @return the function has no return
 */
void DFS_Visit(node *graph,int i, int size);

#endif
