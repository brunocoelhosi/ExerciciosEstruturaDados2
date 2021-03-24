#include <stdio.h>
#include <stdlib.h>

int calculaSeq(int *vet, int n){

	int max_atual=0, max_total=-1;

	for(int i=0; i<n; i++){

		max_atual+=vet[i];

		if(max_atual<0)

			max_atual=0;

		if(max_atual>max_total)

			max_total = max_atual;
    }

	return max_total;

}

int main(void){

	int N, *vet;

	scanf("%d", &N);

	while(N!=0){

		vet = malloc(sizeof(int)*N);

		for(int i=0; i<N; i++){

			scanf("%d", &vet[i]);

		}
		int result = calculaSeq(vet, N);

		if(result==0)

			printf("Sequência perdedora.\n");

		else
			printf("Maior sequência ganhadora é %d.\n", result);

		scanf("%d", &N);
	}

}
