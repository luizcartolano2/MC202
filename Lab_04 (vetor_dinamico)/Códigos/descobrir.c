do{
  scanf("%c",&esp);
}while((esp == ' ') && (esp != '\n'));

//aqui fazemos um novo loop para ler os caracteres ate encontrarmos o fim de linha
while(1){
  if(esp == '\n'){
    buffer[j] = '\0';
    break;
  }else{
    buffer[j] = esp;
    j++;
    scanf("%c",&esp);
  }
}

//considerando q podemos ter espacos antes do fim de linha, fazemos um loop lendo de "traz pra frente" eliminando estes
for(l = j - 1; buffer[l] ==  ' '; l--){
  buffer[l] = '\0';
}
