#include <stdio.h>
#include <string.h>

void compara(char str[40], char sub[40])
{
    int tamanhoStr = strlen(str);
    int tamanhoSub = strlen(sub);

    int cont = 0;
    int aux[40];
    for (int i = 0; i <= tamanhoStr - tamanhoSub; i++)
    {
        int j;
        for (j = 0; j < tamanhoSub; j++)
        {
            if (str[i + j] != sub[j])
            {
                break;
            }
        }

        if (j == tamanhoSub)
        {
            aux[cont] = i;
            cont++;
        }
    }

    if (cont == 0)
    {
        printf("Repetições: 0\n");
        return;
    }
    else
    {
        printf("Repetições: %d\n", cont);
        printf("Posições: ");
        for (int i = 0; i < cont; i++)
        {
            printf("%d ", aux[i]);
        }
    }
}

void minusculas(char string[40])
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}

int main()
{
    char str[40], sub[40];

    fgets(sub, 40, stdin);
    fgets(str, 40, stdin);

    str[strcspn(str, "\n")] = '\0';
    sub[strcspn(sub, "\n")] = '\0';

    minusculas(str);
    minusculas(sub);

    compara(str, sub);

    return 0;
}