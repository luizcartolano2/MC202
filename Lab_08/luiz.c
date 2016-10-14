#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definição da estrutura dos nós da árvore
typedef struct arv{
  int data;
  struct arv *left;
  struct arv *right;
}arv;

//funções de impressão
void pre_ordem_print(arv *Arv);
void em_ordem_print(arv *Arv);
void pos_ordem_print(arv *Arv);
void arv_size(arv *Arv,int level);

//funções auxiliares
arv* arv_lib(arv *a);
int height(arv *Arv);
arv* sucessor(arv *Arv);
arv* create(int dado);

//funções de busca
arv* search(arv *Arv, int dado);
arv* minimo(arv *Arv);
arv* maximo(arv *Arv);

//funções de manipulação da árvore
arv* insert(arv *Arv, arv *new);
arv* delete(arv *Arv, int dado);

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

void pos_ordem_print(arv *Arv){
    /*Funcao que imprime a árvore em pós-ordem, isto é, primeiro verificamos se o no
    requisitado existe ou nao, caso ele exista chamamos a funcao para o filho da esquerda,
    assim, percorreremos todo o lado esquerdo da arvore, depois disso, percorreremos o lado direito
    e por fim imprimiremos o no principal*/
    if(Arv != NULL){
      pos_ordem_print(Arv->left);
      pos_ordem_print(Arv->right);
      printf("%d ",Arv->data);
    }

}
void pre_ordem_print(arv *Arv){
    /*Funcao que imprime a arvore em pre-ordem, isto é, printamos a raiz
    depois seu filho a esquerda e depois o filho a direita*/

    if(Arv != NULL){
      printf("%d ",Arv->data);
      pre_ordem_print(Arv->left);
      pre_ordem_print(Arv->right);
    }

}
void em_ordem_print(arv *Arv){
    /*Funcao que imprime a arvore em-ordem, isto é, primeiro imprimos o filho a esquerda,
    depois imprimos a raiz e por fim os filhos a direita*/

    if(Arv != NULL){
      em_ordem_print(Arv->left);
      printf("%d ",Arv->data);
      em_ordem_print(Arv->right);
    }
}
void arv_size(arv *Arv, int level){
  //primeiro verificamos se a arvore existe
  if(Arv == NULL)
    return;

  //aqui temos o caso base da nossa funcao, que é quando chegamos ao nivel básico
  if(level == 1)
    printf("%d ",Arv->data);

  /*se nao estivermos no caso base, chamamos a funcao para os no filhos da esquerda
  e tiramos um de "level" de modo que quando chegarmos ao caso base estaremos no
  nivel necessario. Faremos o mesmo para o lado direito*/
  else if(level > 1){
    arv_size(Arv->left,level-1);
    arv_size(Arv->right,level-1);
  }

}

//funções auxiliares
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
int height(arv *Arv){
  /*Funcao que calcula a altura da arvore, que sera utilizada na funcao de impressao por nivel,
  chamamos a funcao para ambos os filhos somando 1 a cada novo no, e depois retornamos o maior lado*/
  int e,d;

  if(Arv == NULL)
    return -1;

  e = height(Arv->left);
  d = height(Arv->right);

  if(e > d)
    return e+1;
    else
      return d+1;

}
arv* create(int dado){
  //funcao responsavel por criar o novo no a ser inserido na arvore e por avisar caso de errado o malloc
  arv* new = (struct arv*)malloc(sizeof(struct arv));
  if(new == NULL){
    printf("memoria insuficiente\n");
    return NULL;
  }

  new->data = dado;
  new->right = NULL;
  new->left = NULL;

  return new;
}
arv* sucessor(arv *Arv){
  //funcao que recebe o no como parametro e retorna o minimo da subarvore a sua direita
    return minimo(Arv->right);
}

//funções de busca
arv* search(arv *Arv, int dado){
  /*Funcao responsavel por procurar um dado na arvore
  Se ele for menor que a raiz procuramos a esquerda, caso contrario a direita*/
  while ((Arv != NULL) && (Arv->data != dado)){
    if(Arv->data < dado)
      Arv = Arv->left;
      else
        Arv = Arv->right;
  }

  return Arv;

}
arv* minimo(arv *Arv){
  /*Funcao responsavel por achar o menor valor da arvore, para isso devemos percorrer a subarvore
  esquerda até infinitos (vulgo chegar em NULL)*/
  if(Arv == NULL)
    return NULL;

  while(Arv->left)
    Arv = Arv->left;

  return Arv;
}
arv* maximo(arv *Arv){
  /*Funcao responsavel por achar o maior valor da arvore, para isso devemos percorrer a subarvore
  direita até infinitos (vulgo chegar em NULL)*/
  if(Arv == NULL)
    return NULL;

  while(Arv->right)
    Arv = Arv->right;

  return Arv;

}

//funções de manipulação da árvore
arv* insert(arv *Arv, arv *new){
  /*Funcao que insere os novos nós na arvore, quando estamos em NULL significa que devemos inserir
  o no em questao, logo, retornamos esse novo nó. Caso contrario comparamos o valor da chave contida
  no novo nó com o "raiz", para saber se devemos inserir a esquerda ou direita. Fazendo isso recursivamente
  ate chegarmos a posicao de insersão. Caso o dado ja exista ele nao entrara em nenhuma das condicoes e retornamos
  apenas a arvore que ja possuimos*/
  if(Arv == NULL)
    return new;

  if(Arv->data > new->data)
    Arv->left = insert(Arv->left,new);
  else if(Arv->data < new->data)
    Arv->right = insert(Arv->right,new);

  return Arv;

}
arv* delete(arv *Arv, int dado){
  //declaracao do auxiliar a ser usado ao longo da funcao
  arv *aux = NULL;
  //caso base
  if(Arv == NULL)
    return Arv;

  //aqui comparamos o valor da chave com o do no que estamos visitamos
  //se ele for menor visitamos o lado esquerdo da raiz, caso contrario o direito
  //se for igual, devemos deletar o no encontrado
  if(dado < Arv->data)
      Arv->left = delete(Arv->left,dado);
  else if(dado > Arv->data)
      Arv->right = delete(Arv->right,dado);
  else{
    //se o nó não tiver filhos we just kill him
    if((Arv->left == NULL) && (Arv->right == NULL)){
      free(Arv);
      return NULL;
    }
    /*caso ele tenha apenas um filho, fazemos um auxiliar apontar para este filho (não queremos criancas perdidas
    pelo mundo né), ai deletamos o nó desejado(sim, teremos órfãos no mundo) e depois retornamos o auxiliar para
    não termos órfãos perdidos, apenas órfãos mesmo*/
    if(Arv->left == NULL){
      aux = Arv->right;
      free(Arv);
      return aux;
    }else if(Arv->right == NULL){
      aux = Arv->left;
      free(Arv);
      return aux;
    }
    //se o no tiver dois filhos, devemos achar seu sucessor para assumir seu lugar (é tipo um responsável legal)
    aux = sucessor(Arv);
    Arv->data = aux->data;
    //como o sucessor nunca possuira um filho a esquerda, chamamos a funcao destroi para tratar de um possivel filho na direita
    Arv->right = delete(Arv->right,aux->data);
  }

  return Arv;

}
