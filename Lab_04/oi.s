//chama a funcao que le a string
char buffer[4000], *str;
int s_size;

scanf(" %[^\n]s",buffer);
s_size = strlen(buffer);


if(data.size == 0){
  //caso o vetor ainda nao tenha sido criado e iremos fazer tal e inserir o primeiro elemento na posicao 2 (1)
  data.size = 2;
  *vetor = (char**)calloc(data.size,sizeof(char*));
  //aqui que ta dando ruim
  (*vetor)[1] = malloc((s_size + 1) * sizeof(char));
  strcpy((*vetor)[1],buffer);
  data.first_ele = 1;
  data.last_ele = 1;
  data.e_Seq++;
}else if((data.last_ele + 1) < (data.size - 1)){
  //caso haja uma posicao livre apos o ultimo elemento, e ele nao seja o ultimo elemento do vetor
  (*vetor)[data.last_ele + 1] = malloc((s_size + 1) * sizeof(char));
  strcpy((*vetor)[data.last_ele + 1],str);
  data.last_ele++;
  data.e_Seq++;
  //chama a funcao que verifica o tamanho do vetor
  **vetor = *verifica_vetor(vetor);
}else{
  if(data.first_ele == 0){
    printf("Fudeu!\n");
  }else{
    (*vetor)[0] = malloc((s_size + 1) * sizeof(char));
    strcpy((*vetor)[0],str);
    data.last_ele = 0;
    data.e_Seq++;
    //chama a funcao que verifica o vetor
    **vetor = *verifica_vetor(vetor);
  }
}
}
