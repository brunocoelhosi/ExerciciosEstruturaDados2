#include <stdio.h>
#include <stdlib.h>

int main () {


    struct consulta{

        int numero_museus;
        int preco_ingressos[100];
        int vezes_cobradas[100];

    };
    struct consulta consulta[100];

    int co=0, i=0, somatorio=0,aux=-1, x;


    do{

        fflush(stdin);
        scanf("\n%d", &consulta[co].numero_museus);
        somatorio = 0;

        for(x=0;x<consulta[co].numero_museus;x++){

            scanf("%d", &consulta[co].preco_ingressos[i]);
            somatorio = consulta[co].preco_ingressos[i] + somatorio;

            if (somatorio % 100 == 0){

                consulta[co].vezes_cobradas[i]++;

            }

        }

        i++;
        aux++;

    }

    while (consulta[co].numero_museus != -1);

    for(i=0;i<aux;i++){

        printf("%d\n",consulta[co].vezes_cobradas[i]);

    }

    return 0;
}

