#include <stdio.h>

int vel_media(int x, int v1, int v2)
{
    int resultado = x / (v1 - v2);
    return resultado;
}

int main()
{
    int x, v1, v2;

    scanf("%d %d %d", &x, &v1, &v2);

    if (v1 > v2)
    {
        int resultado = vel_media(x, v1, v2);
        printf("%ds\n", resultado);
    }
    else
    {
        printf("impossivel\n");
    }

    return 0;
}
