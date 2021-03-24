#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    struct pedidos{

        int numero_escolhas;
        int numero_repeticoes;
        int numero_alimentos;
        int escolhido[100];

    };
    struct pedidos pedidos[100];

    int pe=0, i=0, x,aux=0, teste[100];

    fflush(stdin);
    scanf("\n%d", &pedidos[pe].numero_escolhas);

    for(x=0;x<pedidos[pe].numero_escolhas;x++){

        teste[i] = 1;

        scanf("%d", &pedidos[pe].numero_alimentos);

        if(pedidos[pe].numero_alimentos < 1 && pedidos[pe].numero_alimentos >= 10000){

            return -1;

        }

        scanf("%d", &pedidos[pe].numero_repeticoes);

        if(pedidos[pe].numero_repeticoes <= 0 && pedidos[pe].numero_repeticoes >= 1000){

            return -1;

        }

        aux = pedidos[pe].numero_repeticoes * 29;
        pedidos[pe].escolhido[i] = abs(aux - pedidos[pe].numero_alimentos) + 1;

        if (aux - pedidos[pe].numero_alimentos < pedidos[pe].numero_alimentos) {

            teste[i] ++;

        }

        if(pedidos[pe].numero_alimentos == 1){

            teste[i] = 29;
            pedidos[pe].escolhido[i] = 1;

        }

        i++;


    }


    for(i=0;i<pedidos[pe].numero_escolhas;i++){

        printf("%d ", teste[i]);
        printf("%d\n", pedidos[pe].escolhido[i]);


    }

    return 0;
}

