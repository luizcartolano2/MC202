//
//
//    Created by Luiz Cartolano
//    RA: 183012
//    Program to implement a minimun heap in C
//
//

#include "lab.h"

heap* create_heap(){
  int i;

  heap *Heap = malloc(10000 * sizeof(heap));
  if(!Heap)
    printf("Deu ruim\n");

  for(i = 0;i < 10000; i++){
    Heap->chave = 0;
    Heap->custo = 0;
  }

  return Heap;

}

void h_insert(heap vetor_heap[], int chave, int custo, int *point_tamanho){
	int posicao;

	//Insere elemento
	vetor_heap[*point_tamanho].chave = chave;
	vetor_heap [*point_tamanho].custo = custo;
	posicao = *point_tamanho;
	*point_tamanho = *point_tamanho + 1;

	//Percorre o vetor de prioridade trocando os elementos
	while (posicao != 0) {
		if (vetor_heap [(posicao-2)/2].chave < vetor_heap [posicao].chave || vetor_heap [(posicao-1)/2].chave < vetor_heap [posicao].chave) {
			if (posicao%2 == 0){
				if (vetor_heap [(posicao-2)/2].chave < vetor_heap [posicao].chave) {
					vetor_heap [posicao].custo = vetor_heap [(posicao-2)/2].custo;
					vetor_heap [posicao].chave = vetor_heap [(posicao-2)/2].chave;
					vetor_heap [(posicao-2)/2].custo = custo;
					vetor_heap [(posicao-2)/2].chave = chave;
				}
				posicao = (posicao-2)/2;
			}
			else{
				if (vetor_heap [(posicao-1)/2].chave < vetor_heap [posicao].chave) {
					vetor_heap [posicao].custo = vetor_heap [(posicao-1)/2].custo;
					vetor_heap [posicao].chave = vetor_heap [(posicao-1)/2].chave;
					vetor_heap [(posicao-1)/2].custo = custo;
					vetor_heap [(posicao-1)/2].chave = chave;
				}
				posicao = (posicao-1)/2;
			}
		}
		else
			break;
	}

	return;
}

void h_hremove(){}

void h_reduce(){}
