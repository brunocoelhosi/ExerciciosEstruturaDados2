#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, x;

    scanf("%d", &n);

    if ((n>0) && (n<= pow(10, 6))){

        printf("K");

        for (x=0;x<=n-2;x++){

            printf("k");
    }

    printf("!");

    }

    else

    return -1;
}