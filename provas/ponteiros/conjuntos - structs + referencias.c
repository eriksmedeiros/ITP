#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *vetor;
    int tamanho;
} conjunto;

void uniao(conjunto *a, int tamanhoA, conjunto *b, int tamanhoB)
{
    int *resultado = NULL;
    int tamTotal = 0;
    int i, j;

    // Alocar memoria para o array 'resultado'
    resultado = (int *)malloc((tamanhoA + tamanhoB) * sizeof(int));

    // Adiciona elementos do primeiro conjunto
    for (i = 0; i < tamanhoA; i++)
    {
        resultado[tamTotal++] = a->vetor[i];
    }

    // Adiciona elementos do segundo conjunto
    for (i = 0; i < tamanhoB; i++)
    {
        int elemento = b->vetor[i];
        int aux = 0;

        for (j = 0; j < tamTotal; j++)
        {
            if (elemento == resultado[j])
            {
                aux = 1;
                break;
            }
        }

        if (!aux)
        {
            resultado[tamTotal++] = elemento;
        }
    }

    // Imprime o resultado

    if (tamTotal == 0)
    {
        printf("A união B == {vazio}\n");
    }
    else
    {
        printf("A união B == {");
        for (i = 0; i < tamTotal; i++)
        {
            printf("%d", resultado[i]);
            if (i < tamTotal - 1)
                printf(" ");
        }
        printf("}\n");
    }

    // Libera memoria
    free(resultado);
}

void intersecao(conjunto *a, int tamanhoA, conjunto *b, int tamanhoB)
{
    int tamMax = (tamanhoA < tamanhoB) ? tamanhoA : tamanhoB;
    int *resultado = (int *)malloc((tamMax) * sizeof(int));
    int tamTotal = 0;
    int i, j;

    for (i = 0; i < tamanhoB; i++)
    {
        int elemento = b->vetor[i];

        for (j = 0; j < tamanhoA; j++)
        {
            if (elemento == a->vetor[j])
            {
                resultado[tamTotal++] = elemento;
                break;
            }
        }
    }

    // Imprime o resultado

    if (tamTotal == 0)
    {
        printf("A interseção B == {vazio}\n");
    }
    else
    {
        printf("A interseção B == {");
        for (i = 0; i < tamTotal; i++)
        {
            printf("%d", resultado[i]);
            if (i < tamTotal - 1)
                printf(" ");
        }
        printf("}\n");
    }
}

int main()
{
    conjunto conjuntoA, conjuntoB;
    int tamanhoA, tamanhoB;
    int i;

    // Ler o tamanho e os elementos do conjunto A
    scanf("%d", &tamanhoA);
    conjuntoA.vetor = (int *)malloc(tamanhoA * sizeof(int));
    conjuntoA.tamanho = tamanhoA;
    for (i = 0; i < tamanhoA; i++)
    {
        scanf("%d", &conjuntoA.vetor[i]);
    }

    // Ler o tamanho e os elementos do conjunto B
    scanf("%d", &tamanhoB);
    conjuntoB.vetor = (int *)malloc(tamanhoB * sizeof(int));
    conjuntoB.tamanho = tamanhoB;
    for (i = 0; i < tamanhoB; i++)
    {
        scanf("%d", &conjuntoB.vetor[i]);
    }

    uniao(&conjuntoA, conjuntoA.tamanho, &conjuntoB, conjuntoB.tamanho);
    intersecao(&conjuntoA, conjuntoA.tamanho, &conjuntoB, conjuntoB.tamanho);

    free(conjuntoA.vetor);
    free(conjuntoB.vetor);

    return 0;
}