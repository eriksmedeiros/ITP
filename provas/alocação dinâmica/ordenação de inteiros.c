#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int ordenar(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

int main()
{
    int *numeros = NULL;
    int tamanho = 0;
    int numero;

    while (scanf("%d", &numero) != EOF)
    {
        tamanho++;
        numeros = (int *)realloc(numeros, tamanho * sizeof(int));

        numeros[tamanho - 1] = numero;
    }

    ordenar(numeros, tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", numeros[i]);
    }

    printf("\n");

    free(numeros);

    return 0;
}