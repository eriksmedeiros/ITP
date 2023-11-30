#include <stdio.h>

int main()
{
    int anos, contador;
    float somatorio, marcas, media;

    contador = 0;
    somatorio = 0;

    scanf("%d", &anos);

    for (int i = 0; i < anos; i++)
    {
        scanf("%f", &marcas);
        if (marcas == -1)
        {
            contador++;
            continue;
        }

        somatorio += marcas;
    }

    media = somatorio / (anos - contador);

    if (contador == anos)
    {
        printf("A competicao nao possui dados historicos!\n");
    }

    else
    {
        printf("%.2f", media);
    }

    return 0;
}