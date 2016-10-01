#include "lab04.h"

int main(void){

  char option[30];
  char **m_array = NULL;

  data.size = 0;

  //loop que chama as funcoes enquanto a opcao escolhida nao for "exit"
  do{
    //leitura da opcao que devera ser executada
    scanf("%s",option);
    if(strcmp(option,"unshift") == 0){
      //funcao que insere uma cadeia no inicio da sequencia
      unshift(&m_array);
      //scanf("\n");
    }
    if(strcmp(option,"shift") == 0){
      shift(&m_array);
      //funcao que retira a primeira cadeia da sequencia
    }
    if(strcmp(option,"print-first") == 0){
      //funcao que imprime a primeira cadeia da sequencia
      print_first(m_array);
    }
    if(strcmp(option,"push") == 0){
      //funcao que insere uma cadeia no fim da sequencia
      push(&m_array);
    }
    if(strcmp(option,"pop") == 0){
      //funcao que retira uma cadeia no fim da sequencia
      pop(&m_array);
    }
    if(strcmp(option,"print-last") == 0){
      //funcao que imprime a ultima cadeia da sequencia
      print_last(m_array);
    }
    if(strcmp(option,"is-empty") == 0){
      //funcao que verifica se a sequencia existe ou nao
      is_empty(m_array);
    }
  }while(strcmp(option,"exit") != 0);

  return 0;

}
