#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int liquida(int total, int *W, int *P, int N){

	int memo[N + 1][total + 1];

	for(int j = 0; j <= total; j++){
		memo[0][j] = 0;
	}

	for(int i = 1; i <= N; i++){
		memo[i][0] = 0;
	}

	for(int i = 1; i <= N; i++)	{

		for(int j = 1; j <= total; j++){

			if(W[i - 1] <= j){

				if((P[i - 1] + memo[i - 1][j - W[i - 1]]) > memo[i - 1][j]){

					memo[i][j] = P[i - 1] + memo[i - 1][j - W[i - 1]];
				}

				else{
					memo[i][j] = memo[i - 1][j];
				}
			}

			else{
				memo[i][j] = memo[i - 1][j];
			}
		}
	}

	return memo[N][total];
}

void freeMemory(int * P, int * W) {
	free(P);
	free(W);
	P = NULL;
	W = NULL;
}

int main (){

    int T = 0, N = 0, *P, *W, G = 0, MW = 0, total = 0;

    scanf("%d", &T);//qnt casos

    if(T < 0 || T>1000){
        return -1;
    }

    do {
        total = 0;
        int max_pessoa = 0;

        fflush(stdin);
        scanf("%d", &N);//numero de conjuntos

        if(N < 0 || N>1000){
            return -1;
        }

        P = malloc(sizeof(int)*N);

        if (P == NULL) {
            printf ("P NULL!\n");
            exit (EXIT_FAILURE);
            freeMemory(P, W);
        }

        W = malloc(sizeof(int)*N);

        if (W == NULL) {
            printf ("W NULL!\n");
            exit (EXIT_FAILURE);
            freeMemory(P, W);
        }

        for(int i=0; i<N; i++){

            scanf("%d%d", &P[i], &W[i]);//preço do item e peso item

            if(P[i] <= 0 || P[i]>100) {
                freeMemory(P, W);
                return -1;
            }

            if(W[i] <= 0){
                freeMemory(P, W);
                return -1;
            }

            if(W[i] > 30) {
                W[i] = 30;
            }

        }

        scanf("%d", &G);//numero pessoas na familia

        if(G <= 0 || G>100){
            freeMemory(P, W);
            return -1;
        }

        for(int i=0;i<G;i++){

            scanf("%d", &MW);//peso maximo que cada uma carrega

            if(MW <= 0) {
                freeMemory(P, W);
                return -1;
            }

            if(MW > 30) {
                MW = 30;
            }

           max_pessoa = liquida(MW, W, P, N);
           total = max_pessoa + total;

        }

        printf("%d\n", total);

        freeMemory(P, W);

        T--;
    }

    while (T != 0);

    return 0;

}
