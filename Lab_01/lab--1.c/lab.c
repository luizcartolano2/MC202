//
//
//  Created by Luiz Eduardo Cartolano
//  RA: 183012
//
//

#include "lab.h"

int main(void){

    int n_lines, n_elements;
    double **line;
    double average = 0, detour = 0;
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

    //aqui faremos a leitura dos dados de entrada e ao mesmo tempo iremos calcular a soma dos valores, a fim de facilitar o calculo da media
    for(i = 0; i < n_lines; i++){
        for(j = 0; j <= i; j++){
            scanf("%lf",&line[i][j]);
            average = average + line[i][j];
        }
    }

    //aqui calculeremos a média dos valores de entrada
    average = average / n_elements;

    //aqui calculeremos o detour padrão dos valores de entrada
    for(i = 0; i < n_lines; i++){
        for(j = 0; j <= i; j++){
            detour = detour + ((line[i][j] - average)*(line[i][j] - average));
        }
    }

    detour = sqrt(detour/n_elements);

    /*agora que ja temos os valores corretos, aqui imprimeros a matriz triangular,
    mudaremos os valores da matriz durante a impressao para economizar memoria*/
    for(i = 0; i < n_lines; i++){
        for(j = 0; j <= i; j++){
            printf("%.12f ",(line[i][j]-average)/detour);
        }
        printf("\n");
    }
    printf("\n");

    printf("%.12lf ",average);
    printf("%.12lf \n",detour);

    //depois de impressos os dados da matriz iremos desalocar a mesma
    for(i = 0; i < n_lines; i++){
        free(line[i]);
    }

    free(line);

    return 0;

}
