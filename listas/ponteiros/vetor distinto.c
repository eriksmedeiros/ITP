#include <stdio.h>
#include <stdlib.h>

void naoSeRepetem(int n, float vet[])
{
    int *p = (int *)malloc(n * sizeof(int));
    int diferentes = 0;

    for (int i = 0; i < n; i++)
    {
        p[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int repetido = 0;

        for (int j = 0; j < n; j++)
        {
            if (i != j && vet[i] == vet[j])
            {
                repetido = 1;
                break;
            }
        }

        if (!repetido)
        {
            p[diferentes] = i;
            diferentes++;
        }
    }

    printf("[");
    for (int i = 0; i < diferentes; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%.4f", vet[p[i]]);
    }
    printf("]");

    free(p);
}

int main()
{
    int n;
    scanf("%d", &n);

    float vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &vet[i]);
    }

    naoSeRepetem(n, vet);

    return 0;
}