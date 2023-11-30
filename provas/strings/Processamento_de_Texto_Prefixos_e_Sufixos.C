#include <stdio.h>
#include <string.h>

void removePrefixo(char palavra[], char prefixo[])
{

    int i, j;

    // Encontra o tamanho do prefixo e da palavra
    int tamanhoPalavra = strlen(palavra);
    int tamanhoPrefixo = strlen(prefixo);

    // Verifica se a palavra começa com o prefixo
    int auxiliar = 1;
    for (i = 0; i < tamanhoPrefixo; i++)
    {
        if (palavra[i] != prefixo[i])
        {
            auxiliar = 0;
            break;
        }
    }

    // Reorganiza a palavra
    if (auxiliar)
    {
        for (j = 0; j < tamanhoPalavra - tamanhoPrefixo; j++)
        {
            palavra[j] = palavra[tamanhoPrefixo + j];
        }

        palavra[j] = '\0';
    }
}

void removeSufixo(char palavra[], char sufixo[])
{

    int i, j;

    // Encontra o tamanho do sufixo e da palavra
    int tamanhoPalavra = strlen(palavra);
    int tamanhoSufixo = strlen(sufixo);

    // Verifica se a palavra termina com o sufixo
    int auxiliar = 1;
    for (i = tamanhoPalavra - tamanhoSufixo, j = 0; i < tamanhoPalavra; i++, j++)
    {
        if (palavra[i] != sufixo[j])
        {
            auxiliar = 0;
            break;
        }
    }

    // Reorganiza a palavra
    if (auxiliar)
    {
        palavra[tamanhoPalavra - tamanhoSufixo] = '\0';
    }
}

int main()
{
    int numPrefixos, numSufixos, i;
    char prefixos[100][10];
    char sufixos[100][10];
    char palavra[100];

    scanf("%d", &numPrefixos);
    for (i = 0; i < numPrefixos; i++)
    {
        scanf("%s", prefixos[i]);
    }

    scanf("%d", &numSufixos);
    for (i = 0; i < numSufixos; i++)
    {
        scanf("%s", sufixos[i]);
    }

    while (scanf("%s", palavra) != EOF && strcmp(palavra, "-1") != 0)
    {

        int numPalavra = strlen(palavra);
        int removeu = 0;
        for (int i = 0; i < numPrefixos; i++)
        {
            removePrefixo(palavra, prefixos[i]);
            if (strlen(palavra) == 0)
            {
                removeu = 1;
                break;
            }
        }

        if (!removeu)
        {
            for (int i = 0; i < numSufixos; i++)
            {
                removeSufixo(palavra, sufixos[i]);
                if (strlen(palavra) == 0)
                {
                    break;
                }
            }
        }

        if (strlen(palavra) > 0)
        {
            printf("%s\n", palavra);
        }
    }

    return 0;
}