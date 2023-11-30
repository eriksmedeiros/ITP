#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pais
{
    char nome[4];
    int populacao;
    float idh;
};

float calcularMedia(struct Pais *paises, int numPaises)
{
    float soma = 0;
    for (int i = 0; i < numPaises; i++)
    {
        soma += paises[i].populacao;
    }
    return soma / numPaises;
}

void imprimirPaises(struct Pais *paises, int numPaises, float mediaPopulacao)
{
    for (int i = 0; i < numPaises; i++)
    {
        if (paises[i].populacao > mediaPopulacao)
        {
            printf("%s\n", paises[i].nome);
        }
    }
}

int main()
{
    struct Pais *paises = NULL;
    int numPaises = 0;
    char nomePais[4];
    int populacao;
    float idh;

    while (1)
    {
        scanf("%s", nomePais);

        if (strcmp(nomePais, "---") == 0)
        {
            break;
        }

        scanf("%d %f", &populacao, &idh);

        paises = (struct Pais *)realloc(paises, (numPaises + 1) * sizeof(struct Pais));

        strcpy(paises[numPaises].nome, nomePais);
        paises[numPaises].populacao = populacao;
        paises[numPaises].idh = idh;

        numPaises++;
    }

    float mediaPopulacao = calcularMedia(paises, numPaises);

    imprimirPaises(paises, numPaises, mediaPopulacao);

    free(paises);

    return 0;
}
