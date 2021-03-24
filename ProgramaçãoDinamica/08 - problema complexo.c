#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <algorithm>

using namespace std;

int maxSum(int *a, int n){

    int melhor = 0, soma = 0;

    for(int i = 0; i < n; i++){
        soma = max(a[i],soma + a[i]);
        melhor = max(melhor,soma);
    }

    return melhor;
}

int main (){

    setlocale(LC_ALL, "Portuguese");

    int comprimento_apostas, aposta = 0, i = 0,aux=0, ganhadores[1000], aux2 = -1;
    int armazena[10000];
    int * pt;
    pt = armazena;

    do{

        scanf ("%d",&comprimento_apostas);

        if (comprimento_apostas < 0 || comprimento_apostas > 10000){

            return -1;

        }

        for (i = 0; i < comprimento_apostas; i++){

            scanf ("%d",&aposta);

            armazena[i] = aposta;

        }


        aux2 = maxSum(pt,comprimento_apostas);

        ganhadores[aux] = aux2;
        aux2 = -1;
        aux++;
    }

       while (comprimento_apostas != 0);

       for(i=0;i<aux-1;i++){

           if (ganhadores[i] > 0){

                 printf ("Maior sequência ganhadora é %d.\n", ganhadores[i]);

              }

            if (ganhadores[i] == 0){

                 printf ("Sequência perdedora.");

              }
       }

    return 0;

}
