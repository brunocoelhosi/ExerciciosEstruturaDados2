#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int memo [7490][5];

int contar(int S[], int m, int N){

    if(N==0){

        return 1;
    }

    if(N<0){

        return 0;

    }

    if(m<=0 && N>=1){

        return 0;

    }

    if(memo[N][m] == 0){

        memo[N][m] = contar (S,m-1,N) + contar (S,m,N-S[m-1]);

        return memo[N][m];
    }

    else return memo[N][m];

}

int main (){


    int S[5] = {1,5,10,25,50};
    int N = 0;
    int m = 5;

    while (scanf("%d", &N) != EOF) {

    printf("%d\n",contar(S,m,N));

    }

    return 0;

}


