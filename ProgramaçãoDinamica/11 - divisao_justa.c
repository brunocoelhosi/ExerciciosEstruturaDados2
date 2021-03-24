#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <limits.h>

int main (){

   int N=0, m=0, i=0,valor=0,total=0, j=0, div=0;

   scanf("%d", &N);

    while(j<N){

        total =0;
        valor = 0;

        scanf("%d", &m);

        if(m <= 0 || m > 100){

        return -1;

        }

        for(i=0;i<m;i++){

            scanf("%d", &valor);

            if(valor < 0 || valor > 500){

                return -1;

            }

            total = total + valor;
            div = total % 2;
        }
        printf("%d\n", div);
        j++;
   }

    return 0;

}


