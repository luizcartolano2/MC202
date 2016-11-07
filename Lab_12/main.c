//
//
//    Created by Luiz Cartolano
//    RA: 183012
//    Program to implement a "matriz esparsa" in C
//
//

#include "lab.h"

int main(int argc, char const *argv[]) {

  first_e = NULL;
  node **vet;
  node *aux;
  int k, i, line, collum, value;

  scanf("%d",&k);
  vet = calloc(k,sizeof(node*));

  for(i = 0; i < k; i++){
    scanf("%d %d %d",&line,&collum,&value);
    vet[i] = new_node(line,collum,value);
    //printf("%d %d %d\n",(vet[i])->line,(vet[i])->collum,(vet[i])->value);
  }

  for(i = 0; i < k; i++)
    m_insert(vet[i]);

  //print_list(first_e);

  while (1){
    scanf("%d %d",&line,&collum);
    if((line == -1) && (collum == -1))
      break;

    aux = verify_node(line,collum);
    if(!aux)
      printf("(%d,%d) = 0\n",line,collum);
    else
      printf("(%d,%d) = %d\n",line,collum,aux->value);
      //printf("oi\n");
  }


  return 0;

}
