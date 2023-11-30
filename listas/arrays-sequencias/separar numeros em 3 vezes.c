#include <stdio.h>
#define TAM 10

int main()
{
    int multiplos_2[TAM];
    int multiplos_3[TAM];
    int nenhum[TAM];

    int cont1 = 0, cont2 = 0, cont3 = 0;

    for (int i = 0; i < 15; i++)
    {
        int n;
        scanf("%d", &n);

        if (n % 2 == 0)
        {
            multiplos_2[cont1] = n;
            cont1++;
        }
        if (n % 3 == 0)
        {
            multiplos_3[cont2] = n;
            cont2++;
        }
        else if (n % 2 != 0 && n % 3 != 0)
        {
            nenhum[cont3] = n;
            cont3++;
        }
    }

    printf("B = [");
    for (int i = 0; i < cont1; i++)
    {

        printf("%d", multiplos_2[i]);

        if (i < cont1 - 1)
        {
            printf(", ");
        }
    }

    printf("]\n");

    printf("C = [");
    for (int i = 0; i < cont2; i++)
    {
        printf("%d", multiplos_3[i]);
        if (i < cont2 - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    printf("D = [");
    for (int i = 0; i < cont3; i++)
    {
        printf("%d", nenhum[i]);
        if (i < cont3 - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}