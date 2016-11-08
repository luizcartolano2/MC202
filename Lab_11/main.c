//
//
//    Created by Luiz Cartolano
//    RA: 183012
//    Program to implement a minimun heap in C
//
//

#include "lab.h"

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int chave;
	int custo;
} node;

int main(int argc, char const *argv[]) {

	int chave;
	int custo;
	int chave_aux;
	int custo_aux;
	int n;
	int c;
	int i;
	int d;
	int z;
	int x;
	int m = 0;
	char comando='w';

	scanf("%d",&n);

	node *H = malloc(n * sizeof(node));
	int *V = calloc(n,sizeof(int));
	for(i=0;i<=n;i++){
		V[i]=-1;
	}


	while(comando!='t'){
		scanf("%c",&comando);
		if(comando == 'i'){
			scanf("%d",&chave);
			scanf("%d",&custo);

			if(V[chave]==-1){

				H[m].chave = chave;
				H[m].custo = custo;
				V[chave] = m;
				c = m;
				d = (m-1)/2;

				while(c != 0 && H[c].custo < H[d].custo ){
						H[c].custo = H[d].custo;
						H[c].chave = H[d].chave;
						V[H[c].chave] = c;

						H[d].custo = custo;
						H[d].chave = chave;
						V[H[d].chave] = d;

						c = d;
						d = (c-1)/2;
					}

					m++;
				}
}

		if(comando == 'm'){
			if(m==0) printf("vazio\n");
			else{
				m--;
				printf("minimo {%d,%d}\n",H[0].chave,H[0].custo);

				chave_aux = H[m].chave;
				custo_aux = H[m].custo;

				H[m].chave = H[0].chave;
				H[m].custo = H[0].custo;
				V[H[m].chave] = -1;

				H[0].chave = chave_aux;
				H[0].custo = custo_aux;
				if(m!=0)V[H[0].chave] = 0;

				z=0;
				x=1;

				if(m==2){
					if(H[0].custo > H[1].custo){
					chave_aux=H[0].chave;
					custo_aux=H[0].custo;
					H[0].custo=H[1].custo;
					H[0].chave=H[1].chave;
    				V[H[0].chave] = 0;
					H[1].custo=custo_aux;
					H[1].chave=chave_aux;
					V[H[1].chave] = 1;
					}
				}

				while(x < m-1 && (H[z].custo > H[x].custo || H[z].custo > H[x+1].custo)){
					if(m==2){
						H[0]=H[1];

						break;
					}
					if(m==1){
						break;
					}
					if(H[x].custo < H[x+1].custo){
						chave_aux = H[x].chave;
						custo_aux = H[x].custo;

						H[x].chave = H[z].chave;
						H[x].custo = H[z].custo;
    					V[H[x].chave] = x;
						H[z].chave = chave_aux;
						H[z].custo = custo_aux;
						V[H[z].chave] = z;

						z = x;
					}
					else{
						chave_aux = H[x+1].chave;
						custo_aux = H[x+1].custo;

						H[x+1].chave = H[z].chave;
						H[x+1].custo = H[z].custo;
						V[H[x+1].chave] = x+1;

						H[z].chave = chave_aux;
						H[z].custo = custo_aux;
						V[H[z].chave] = z;

						z = x+1;
					}

					x = z*2+1;

				}
			}
		}

		if(comando=='d'){
			scanf("%d",&chave);
			scanf("%d",&custo);

			c = V[chave];
			d = (c-1)/2;

			H[c].custo = custo;

			while(c != 0 && H[c].custo < H[d].custo ){
				H[c].custo = H[d].custo;
				H[c].chave = H[d].chave;
				V[H[c].chave] = c;

				H[d].custo = custo;
				H[d].chave = chave;

				V[H[d].chave] = d;

				c = d;
				d = (c-1)/2;
			}
		}
	}

	free(H);
	free(V);
	return 0;
}
