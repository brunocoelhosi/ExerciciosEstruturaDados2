#include <stdio.h>
#include <stdlib.h>

int maxSum(int *apostas, int comprimento){

	int atual = 0 , melhor_soma = -1;

	for(int i = 0; i < comprimento; i++){

		atual += apostas[i];

		if(atual < 0){

			atual=0;

		}

		if(atual>melhor_soma){

			melhor_soma = atual;
		}
	}

	return melhor_soma;

}


int main(void){

	int *apostas, N;

	scanf("%d", &N);

	while(N!=0){

		apostas = malloc(sizeof(int)*N);

		for(int i=0; i<N; i++){

			scanf("%d", &apostas[i]);

		}

		int aux = maxSum(apostas, N);

		if(aux == 0){

			printf("Sequência perdedora.\n");

		}

		else{

			printf("Maior sequência ganhadora é %d.\n", aux);

		}

		scanf("%d", &N);
	}

}
