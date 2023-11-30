#include <stdio.h>
#include <string.h>

int busca(char c, char texto[50])
{
    int encontrou = 0;

    for (int i = 0; i < 50; i++)
    {
        if (texto[i] == '\0')
        {
            break;
        }

        if (texto[i] == c)
        {
            encontrou = 1;
        }
    }

    return encontrou;
}

void compare(char padrao[50], char texto[50], int tamanhoPadrao, int tamanhoTexto)
{
    for (int i = 0; i < tamanhoTexto; i++)
    {
        int coincide = 1;
        for (int j = 0; j < tamanhoPadrao; j++)
        {
            if (tamanhoTexto - i < tamanhoPadrao || !coincide)
            {
                coincide = 0;
                break;
            }

            if (texto[i + j] != padrao[j])
            {
                coincide = 0;
                printf("%c não\n", texto[i + j]);
                if (!busca(texto[i + j], padrao))
                {
                    i = i + j;
                }
            }
            else
            {
                printf("%c ", texto[i + j]);
            }
        }

        if (coincide)
        {
            printf("sim\n");
            printf("Achei o padrão no índice %d\n", i);
            return;
        }
    }

    printf("Não achei o padrão\n");
}

int main()
{

    char padrao[50], texto[50];
    int tamanhoPadrao, tamanhoTexto;

    scanf("%s[^\n]", texto);
    scanf("%s[^\n]", padrao);

    tamanhoPadrao = strlen(padrao);
    tamanhoTexto = strlen(texto);

    compare(padrao, texto, tamanhoPadrao, tamanhoTexto);

    return 0;
}