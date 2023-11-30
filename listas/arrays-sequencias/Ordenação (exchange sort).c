#include <stdio.h>

void exchangesort(int quantidade, int vetor[], int aux[][100])
{
    int i, j, k;
    int temp;

    for (i = 0; i < quantidade - 1; i++)
    {
        for (j = i + 1; j < quantidade; j++)
        {
            if (vetor[i] > vetor[j])
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }

        // Copie o estado atual do vetor para a matriz aux
        for (k = 0; k < quantidade; k++)
        {
            aux[i + 1][k] = vetor[k];
        }
    }
}

int main()
{
    int A[100];
    int aux[100][100];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++)
    {
        aux[0][i] = A[i];
    }

    exchangesort(n, A, aux);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }

    return 0;
}
