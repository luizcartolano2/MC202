#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(void){

  int n_lines, n_elements;
  double **line;
  double soma = 0, media, somatorio = 0, desvio;
  int i, j;

  //primeiro faremos a leitura do numero de linhas e calculeremos o numero de elementos da matriz
  scanf("%d",&n_lines);
  n_elements = ((n_lines * n_lines) + n_lines)/2;

  //agora faremos a alocação da matriz
  //primeiro alocaremos um vetor de ponteiros
  line = (double**)malloc(n_lines * sizeof(double*));

  //depois alocaremos um novo vetor para cada ponteiro do vetor previamente alocado
  for(i = 0; i < n_lines; i++){
    line[i] = (double*)malloc((i+1) * sizeof(double));
  }

  //aqui faremos a leitura dos dados de entrada
  for(i = 0; i < n_lines; i++){
    for(j = 0; j <= i; j++){
      scanf("%lf",&line[i][j]);
    }
  }

  //aqui calculeremos a média dos valores de entrada
  for(i = 0; i < n_lines; i++){
    for(j = 0; j <= i; j++){
      soma = soma + line[i][j];
    }
  }

  media = soma / n_elements;

  //aqui calculeremos o desvio padrão dos valores de entrada
  for(i = 0; i < n_lines; i++){
    for(j = 0; j <= i; j++){
      somatorio = somatorio + ((line[i][j] - media)*(line[i][j] - media));
      }
    }

    desvio = sqrt(somatorio/n_elements);

  //aqui faremos as mudancas solicitadas nos valores da matriz triangular
  for(i = 0; i < n_lines; i++){
    for(j = 0; j <= i; j++){
      line[i][j] = (line[i][j] - media)/desvio;
    }
  }

  for(i = 0; i < n_lines; i++){
    for(j = 0; j <= i; j++){
      printf("%.12f ",line[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("%.12lf ",media);
  printf("%.12lf\n",desvio);

  return 0;

}
