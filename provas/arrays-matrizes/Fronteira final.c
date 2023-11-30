#include <stdio.h>
#define TAM 100

int main()
{
    int n1, n2;
    int i, j;
    char simb;

    scanf("%d %d", &n1, &n2);

    char mapa[n1][n2];

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            scanf(" %c", &mapa[i][j]);
        }
    }

    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            switch (mapa[i][j])
            {
            case '~':
                cont1++;
                break;
            case 'X':
                cont2++;
                break;
            case '^':
                cont3++;
                break;
            case '*':
                cont4++;
                break;
            case '.':
                cont5++;
                break;
            default:
                printf("Operador inválido.\n");
            }
        }
    }

    if (cont1 >= (n1 * n2) / 2 && cont4 >= (n1 * n2) * 0.20 && cont2 == 0)
    {
        printf("Planeta Classe M\n");
    }
    else if (cont2 > 0)
    {
        printf("Planeta Hostil\n");
    }
    else if (cont1 >= (n1 * n2) * 0.85)
    {
        printf("Planeta Aquático\n");
    }
    else if (cont3 >= (n1 * n2) * 0.60)
    {
        printf("Planeta Desértico\n");
    }
    else if (cont4 >= (n1 * n2) * 0.65)
    {
        printf("Planeta Selvagem\n");
    }
    else if (cont1 >= (n1 * n2) * 0.85)
    {
        printf("Planeta Hostil\n");
    }
    else
    {
        printf("Planeta Inóspito\n");
    }
    return 0;
}