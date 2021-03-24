#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;


int const p = 1e5 + 1;
int distancia, mat[10][p], mat2[10][p];


int calculo_min(int w, int y)
{
    if(y == distancia){

        if(w == 9){

        return 0;

        }

        else{

        return 1e9 + 1;

        }
    }

    int &val = mat2[w][y];

    if(val != -1){

        return val;
    }

    val = 1e9 + 1;

    if(w > 0) val = min(val, calculo_min(w - 1, y + 1) + 60);
    if(w < 9) val = min(val, calculo_min(w + 1, y + 1) + 20);

    val = min(val, calculo_min(w, y + 1) + 30);

    return val = val - mat[w][y];
}

int main()
{
    int testes;
    scanf("%d", &testes);

    while(testes-- != 0)
    {
        distancia = 0;

        scanf("%d", &distancia);

        distancia /= 100;

        for(int i = 0; i < 10; ++i)
            for(int j = 0; j < distancia; ++j)
                scanf("%d", &mat[i][j]);

        memset(mat2, -1, sizeof mat2);

        printf("%d\n\n", calculo_min(9, 0));
    }

    return 0;
}
