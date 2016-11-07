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

	scanf("%d",&n);

  heap *Heap = malloc(n * sizeof(heap));
  if(!Heap)
    printf("Deu ruim\n");

  for(i = 0;i < n; i++){
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
		if (vetor_heap [(posicao-2)/2].custo > vetor_heap [posicao].custo || vetor_heap [(posicao-1)/2].custo > vetor_heap [posicao].custo) {
			if (posicao%2 == 0){
				if (vetor_heap [(posicao-2)/2].custo > vetor_heap [posicao].chave) {
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

heap h_remove(heap vetor_heap[], int *point_tamanho) {
	int posicao;

	heap aux;
	aux.chave = vetor_heap[0].chave;
	aux.custo = vetor_heap[0].custo;

	*point_tamanho = *point_tamanho - 1;
	vetor_heap [0].chave = vetor_heap [*point_tamanho].chave;
	vetor_heap [0].custo = vetor_heap [*point_tamanho].custo;
	posicao = 0;

	//Percorre o vetor trocando os elementos
	while (posicao < *point_tamanho) {
		if (vetor_heap [posicao].chave < vetor_heap [2*posicao+1].chave || vetor_heap [posicao].chave < vetor_heap [2*posicao+2].chave) {
			if (vetor_heap [2*posicao+1].chave > vetor_heap [2*posicao+2].chave) {
				vetor_heap [posicao].chave = vetor_heap [2*posicao+2].chave;
				vetor_heap [posicao].custo = vetor_heap [2*posicao+2].custo;
				vetor_heap [2*posicao+2].chave = vetor_heap [*point_tamanho].chave;
				vetor_heap [2*posicao+2].custo = vetor_heap [*point_tamanho].custo;
				posicao = 2*posicao+2;
			}
			else {
				vetor_heap [posicao].chave = vetor_heap [2*posicao+1].chave;
				vetor_heap [posicao].custo = vetor_heap [2*posicao+1].custo;
				vetor_heap [2*posicao+1].chave = vetor_heap [*point_tamanho].chave;
				vetor_heap [2*posicao+1].custo = vetor_heap [*point_tamanho].custo;
				posicao = 2*posicao+1;
			}
		}
		else {
			break;
		}
	}

	return aux;

}

void h_reduce(heap vetor_heap[], int chave, int custo, int *point_tamanho){
	int i, posicao = 0;

	for(i = 0; i < n; i++){
		if(chave == vetor_heap[i].chave){
			vetor_heap[i].custo = custo;
			break;
		}
	}

	while (posicao < tamanho_heap) {
		if (vetor_heap [posicao].chave < vetor_heap [2*posicao+1].chave || vetor_heap [posicao].chave < vetor_heap [2*posicao+2].chave) {
			if (vetor_heap [2*posicao+1].chave > vetor_heap [2*posicao+2].chave) {
				vetor_heap [posicao].chave = vetor_heap [2*posicao+2].chave;
				vetor_heap [posicao].custo = vetor_heap [2*posicao+2].custo;
				vetor_heap [2*posicao+2].chave = vetor_heap [*point_tamanho].chave;
				vetor_heap [2*posicao+2].custo = vetor_heap [*point_tamanho].custo;
				posicao = 2*posicao+2;
			}
			else {
				vetor_heap [posicao].chave = vetor_heap [2*posicao+1].chave;
				vetor_heap [posicao].custo = vetor_heap [2*posicao+1].custo;
				vetor_heap [2*posicao+1].chave = vetor_heap [*point_tamanho].chave;
				vetor_heap [2*posicao+1].custo = vetor_heap [*point_tamanho].custo;
				posicao = 2*posicao+1;
			}
		}
		else {
			break;
		}
	}


	return;

}
