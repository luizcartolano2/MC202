#include "lab04.h"

// void printa_tudo_unicamp(char** vetor){
//   int i;
//   printf("\t [F] %d\n",data.first_ele);
//   printf("\t [L] %d\n",data.last_ele);
//   printf("\t [S] %d\n",data.size);
//   for(i=0; i<data.size; i++){
//     printf("\t[%2d] %s\n",i,vetor[i]);
//   }
//   printf("\n");
// }

// Le uma string de tamanho até 1500, e cria o menor vetor possivel pra armazenar a string.
char* read_string(){
  char buffer[1500],buffer_2[1500],esp, *str;
  int s_size, i = 0, j = 0, l;

  do{
    scanf("%c",&esp);
  }while((esp == ' ') && (esp != '\n'));

  //aqui fazemos um novo loop para ler os caracteres ate encontrarmos o fim de linha
  while(esp != '\n'){
      buffer[j] = esp;
      j++;
      scanf("%c",&esp);
  }
  buffer[j] = '\0';
  
  //considerando q podemos ter espacos antes do fim de linha, fazemos um loop lendo de "traz pra frente" eliminando estes
  for(l = j - 1; buffer[l] ==  ' '; l--){
    buffer[l] = '\0';
  }

  s_size = strlen(buffer);

  str = malloc(s_size + 1 * sizeof(char));

  strcpy(str,buffer);

  return str;

}


// Verifica se tem alguma palavra no vetor
void is_empty(char **vetor){
  // Se tem alguma coisa alocada no vetor (VAI DAR TRETAAAAAAAA) (OU NAOO)
  if(data.size == 0)
    printf("yep\n");
  else
    printf("nope\n");
  return;
}

// Imprime a primeira palavra do vetor circular
void print_first(char **vetor){
  if(data.size == 0)
    return;

  printf("%s\n",vetor[data.first_ele]);
  return;
}

// Imprime a ultima palavra do vetor circular
void print_last(char **vetor){
  if(data.size == 0)
    return;

  printf("%s\n",vetor[data.last_ele]);
  return;
}

// Insere uma palavra no final do vetor circular
void push(char ***vetor){
  char *str = read_string();

  // Caso o vetor esteja vazio
  if(data.size == 0){
    data.size = 2;

    (*vetor) = calloc(data.size,sizeof(char*));
    (*vetor)[1]=str;

    data.first_ele = 1;
    data.last_ele = 1;
  }
  else{

    // Caso tenha espaço até o final do vetor
    if((data.last_ele + 1) < data.size){

      (*vetor)[data.last_ele + 1] = str;
      data.last_ele++;

      *vetor = verifica_vetor(vetor);
    }

    // Caso o ultimo elemento esteja no final do vetor
    else{
      if(data.first_ele == 0){
        printf("Fudeu!\n");
      }
      else{
        (*vetor)[0]=str;
        data.last_ele = 0;

        *vetor = verifica_vetor(vetor);
      }
    }
  }
}

// Libera a ultima palavra do vetor circular
void pop(char ***vetor){
  if(data.size==0)
    return;

  // Se o vetor possui apenas uma palavra
  if(data.size == 2){
    // Libero a palavra
    free((*vetor)[data.last_ele]);
    data.first_ele = -1;
    data.last_ele = -1;
    data.size = 0;

    // Libero o vetor (back to the beginning)
    free(*vetor);
    *vetor = NULL;
  }

  else{
    // Se o ultimo elemento não está na posição 0
    if(data.last_ele != 0){
      // printf("\t[%d]\n",data.last_ele);
      free((*vetor)[data.last_ele]);
      (*vetor)[data.last_ele]=NULL;
      data.last_ele--;

      // printa_tudo_unicamp(*vetor);

      *vetor = verifica_vetor(vetor);
    }
    // Se o ultimo elemento está na posição 0
    else{
      if(data.first_ele == data.size - 1)
        printf("Pruuu\n");

      free((*vetor)[data.last_ele]);
      data.last_ele = data.size - 1;

      // printa_tudo_unicamp(*vetor);

      *vetor = verifica_vetor(vetor);
    }
  }
}

// Verifica se precisa ajustar o tamanho do vetor
char** verifica_vetor(char*** vetor){
  int i, contador = 0 /*,teste = 0*/;

  if(data.first_ele<=data.last_ele){
    contador=data.last_ele-data.first_ele+1;
  }
  else{
    contador=data.size-(data.first_ele-1) + data.last_ele;
  }


  if(contador >= data.size){
    //se a variavel teste for igual a zero, significa que todos os espaços estão ocupados, assim, devemos dobrar o tamanho do vetor
    return dobra_vetor(vetor);
  }
  else{
    if(contador <= data.size/4){
      //se a variavel teste equivaler a 1/4 do tamanho do vetor, significa que devemos diminuir o mesmo
      return diminui_vetor(vetor);
    }
  }

  return *vetor;
}

char** dobra_vetor(char*** vetor){
  int i, j, teste = 0;

  // Vetor novo, cara nova
  char **new = (char**)calloc(data.size*2,sizeof(char*));

  // Percorro os vetores copiando de um para o outro
  // Loop infinito, mas posso para quando i completa uma volta, ou quando j == data.size
  // No caso, vou colocar 2 condições, uma no FOR, e outra dentro do FOR
  // Sim, eu posso fazer isso com o FOR. São 2 inicializações de variavel: i= <aquilo> e j=0 (São separados por virgulas simples)
  // for(         ,          ;             ;   )
  //
  for(i = data.first_ele, j=0; j<data.size ;j++){
    new[j]=(*vetor)[i];
    i=(i+1)%data.size;

    // Saio do Loop quando meu i completa uma volta inteira
    if(i==data.first_ele)
      break;
  }

  // Arrumo algumas variaveis
  data.first_ele = 0;
  data.last_ele = j;
  data.size = data.size * 2;

  free(*vetor);
  return new;
}

char** diminui_vetor(char*** vetor){
  //printf("\t[%d -->",data.size);
  int i, j, teste = 0;

  // Vida nova, ficha limpa
  char **new = (char**)calloc(data.size/2,sizeof(char*));

  // Percorre os vetores, copiando de um para o outro. Paro quando ultrapasso o ultimo elemento do vetor original. Como o vetor nunca estará cheio, essa condição funciona :)
  for(i = data.first_ele, j=0; i!=data.last_ele+1 ;j++){
    new[j]=(*vetor)[i];
    i=(i+1)%data.size;
  }

  // Arrumando algumas coisas
  data.first_ele = 0;
  data.last_ele = j-1;
  data.size = data.size / 2;
  //printf(" %d]\n",data.size);
  free(*vetor);
  return new;
}

//remove a primeira posicao do vetor
void shift(char*** vetor){
  if(data.size==0)
    return;

  // Se o vetor possui apenas uma palavra
  if(data.size == 2){
    // Libero a palavra
    free((*vetor)[data.first_ele]);
    (*vetor)[data.first_ele]=NULL;

    data.first_ele = -1;
    data.last_ele = -1;
    data.size = 0;

    // Libero o vetor (back to the beginning)
    free(*vetor);
    *vetor = NULL;
  }

  else{
    if(data.first_ele == (data.size - 1)){
      free((*vetor)[data.first_ele]);
      (*vetor)[data.first_ele]=NULL;
      data.first_ele = 0;

      *vetor = verifica_vetor(vetor);
    }else{

      free((*vetor)[data.first_ele]);
      (*vetor)[data.first_ele]=NULL;
      data.first_ele++;

      *vetor = verifica_vetor(vetor);
    }
  }
}

//insere na primeira posicao do vetor
void unshift(char*** vetor){

  char *str = read_string();

  // Caso o vetor esteja vazio
  if(data.size == 0){
    data.size = 2;

    (*vetor) = calloc(data.size,sizeof(char*));
    (*vetor)[0]=str;

    data.first_ele = 0;
    data.last_ele = 0;
  }
  else{

    // Caso tenha espaço até o final do vetor
    if((data.first_ele - 1) >= 0){

      (*vetor)[data.first_ele - 1] = str;
      data.first_ele--;

      *vetor = verifica_vetor(vetor);
    }

    // Caso o ultimo elemento esteja no comeco do vetor
    else{

        (*vetor)[data.size - 1] = str;
        data.first_ele = data.size - 1;

        *vetor = verifica_vetor(vetor);
    }
  }
}
