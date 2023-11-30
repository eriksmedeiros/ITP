#include <stdio.h>

void uniao(int conj1[], int tam1, int conj2[], int tam2)
{
    int resultado[100];
    int tamTotal = 0;

    // Adicionar elementos do primeiro conjunto
    for (int i = 0; i < tam1; i++)
    {
        resultado[tamTotal++] = conj1[i];
    }

    // Adicionar elementos do segundo conjunto
    for (int i = 0; i < tam2; i++)
    {
        int elemento = conj2[i];
        int temp = 0;

        // Verificar se o elemento já está no resultado
        for (int j = 0; j < tamTotal; j++)
        {
            if (resultado[j] == elemento)
            {
                temp = 1;
                break;
            }
        }

        if (!temp)
        {
            resultado[tamTotal++] = elemento;
        }
    }

    // Imprimir a união dos conjuntos
    for (int i = 0; i < tamTotal; i++)
    {
        printf("%d ", resultado[i]);
    }
    printf("\n");
}

int main()
{
    int conj1[100], tam1, conj2[100], tam2;

    scanf("%d %d", &tam1, &tam2);

    for (int i = 0; i < tam1; i++)
    {
        scanf("%d", &conj1[i]);
    }

    for (int i = 0; i < tam2; i++)
    {
        scanf("%d", &conj2[i]);
    }

    uniao(conj1, tam1, conj2, tam2);

    return 0;
}