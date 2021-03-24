#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <limits.h>

int LIS (int A[], int i, int *v) {

    int memo[i];
    memo[0] = 1;
    int aux = i;
    int k = 0;

    int tmp , max = INT_MIN;

    for (int i = 1; i < aux ; i++) {

        memo[i] = 1;

        for (int j = 0; j < i ; j++) {

            if (A[j] < A[i] ){

            tmp = memo[j] +1;

            }

            if (tmp > memo[i] ) {

                memo[i] = tmp ;


                if (tmp > max){

                    max = tmp ;

                }
            }
        }
     }

    for(i = 1; i <= aux;i++){

            if(memo[i-1] == memo[i]){
                v[k] = i ;
            }

            if(memo[i-1] < memo[i]) {
                v[k] = i-1;
                k++;
            }

            if(memo[i] > memo[i-1]){
                v[k] = i;

            }

    }

    return max ;
}




int main (){

    setlocale(LC_ALL, "Portuguese");

    int numero_casos=0, conjunto[1000], i=0, acertos[1000], tamanho=0;
    char altitudes[1000];
    int *v = malloc(10 * sizeof(int));;

    fflush(stdin);
    scanf ("%d",&numero_casos);

    if (numero_casos <= 0){

        return -1;

    }

    printf("\n");

    int aux=0;
    for(int aux2=0;aux2<numero_casos;aux2++){

    fflush(stdin);
    fgets(altitudes,1,stdin);

        do{


            fflush(stdin);
            fgets(altitudes,10,stdin);
            conjunto[i] = atoi(altitudes);
            tamanho++;
            i++;

        }

            while (altitudes[0] != ' ');

            for(i=0;i<tamanho-1;i++){
                   printf("\nvalores de i%d: %d",i,conjunto[i]);
            }



           acertos[aux] = LIS(conjunto,tamanho-1,v);

           printf("valor de i:%d",i);

           aux++;

        }

    for(i = 0; i < numero_casos;i++){

        printf("Acertos: %d\n", acertos[i]);

        for(int j = 0; j < acertos[i];j++){

            printf("\n%d",conjunto[v[j]]);

        }

   }

    return 0;

}


