//
//
//    Created by Luiz Cartolano
//    RA: 183012
//
//
#include"lab.h"

int main(void){

  arv *Arv = NULL, *teste = NULL;
  char buffer[30];
  int h, i, dado, aux;

  do{
    scanf("%s",buffer);
    if(strcmp(buffer,"inserir") == 0){
      //funcao que insere um no ordenado
      scanf("%d",&dado);
      teste = create(dado);
      if(teste != NULL)
        //printf("memoria insuficiente\n");
      //else
        Arv = insert(Arv,teste);
    }
    if(strcmp(buffer,"excluir") == 0){
      //funcao que remove um no da arvore
      scanf("%d",&dado);
      Arv = delete(Arv,dado);
    }
    if(strcmp(buffer,"buscar") == 0){
      //funcao que busca um no na arvore
      scanf("%d",&dado);
      teste = search(Arv,dado);
      if(teste == NULL)
        printf("nao pertence\n");
        else
          printf("pertence\n");
    }
    if(strcmp(buffer,"minimo") == 0){
      //funcao que busca o menor no na arvore
      teste = minimo(Arv);
      if(teste == NULL)
        printf("vazia\n");
        else{
          printf("%d\n",teste->data);
        }
    }
    if(strcmp(buffer,"maximo") == 0){
      //funcao que busca o maior no na arvore
      teste = maximo(Arv);
      if(teste == NULL)
        printf("vazia\n");
        else{
          printf("%d\n",teste->data);
        }
    }
    if(strcmp(buffer,"pos-ordem") == 0){
      //funcao que imprime os nos em pos-ordem
      if(Arv == NULL)
        printf("vazia\n");
      else{
        pos_ordem_print(Arv);
        printf("\n");
      }
    }
    if(strcmp(buffer,"pre-ordem") == 0){
      //funcao que imprime os nos em pre-ordem
      if(Arv == NULL)
        printf("vazia\n");
      else{
        pre_ordem_print(Arv);
        printf("\n");
      }
    }
    if(strcmp(buffer,"em-ordem") == 0){
      //funcao que imprime os nos em-ordem
      if(Arv == NULL)
        printf("vazia\n");
      else{
        em_ordem_print(Arv);
        printf("\n");
      }
    }
    if(strcmp(buffer,"largura") == 0){
      //primeiro chama a funcao que calcula a altura da arvore e depois a funcao recursiva que imprime a arvore em largura
      h = height(Arv);
      if(h != -1){
        for(i = 1; i <= h + 1; i++)
          arv_size(Arv,i);
      }else
        printf("vazia");
      printf("\n");
    }
  }while(strcmp(buffer,"terminar") != 0);

  //liberando a memoria da arvore
  Arv = arv_lib(Arv);

  return 0;

}
