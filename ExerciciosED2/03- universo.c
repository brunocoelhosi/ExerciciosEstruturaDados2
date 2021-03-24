#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {


    struct consulta{

        int mensagens;
        char planeta [50][100];
        int a[100];
        int t[100];
        int real[100];
        char ganhador[50][100];
        int comparacao;

    };
    struct consulta consulta[100];

    int co=0, i=0, x, aux=0;
    consulta[co].comparacao = 0;

    do{

        fflush(stdin);
        scanf("\n%d", &consulta[co].mensagens);

        for(x=0;x<consulta[co].mensagens;x++){

            scanf("%s", consulta[co].planeta[i]);

            if (strlen(consulta[co].planeta[i]) == 0){

                return -1;

            };


            scanf("%d", &consulta[co].a[i]);

            if(consulta[co].a[i] < 2021 && consulta[co].a[i] > 3210){

                return -1;
            }

            scanf("%d", &consulta[co].t[i]);

            if(consulta[co].t[i] <= 0 && consulta[co].t[i] > 1000){

                return -1;
            }

            consulta[co].real[i] = consulta[co].a[i] - consulta[co].t[i];

            if (consulta[co].comparacao == 0){

                consulta[co].comparacao = consulta[co].real[i];

            }

            if (consulta[co].real[i] <= consulta[co].comparacao){

                consulta[co].comparacao = consulta[co].real[i];
                strcpy(consulta[co].ganhador[i], consulta[co].planeta[i]);

            }
        }

        i++;
        aux++;
        consulta[co].comparacao = 0;
    }

    while (consulta[co].mensagens != 0);

    for(i=0;i<aux-1;i++){

        printf("%s\n", consulta[co].ganhador[i]);

    }

    return 0;
}

