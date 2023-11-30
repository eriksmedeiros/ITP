#include <stdio.h>

int main()
{
    int original, digito, numero;
    int invertido = 0;

    scanf("%d", &original);

    numero = original;

    while (numero > 0)
    {
        digito = numero % 10;
        invertido = invertido * 10 + digito;
        numero /= 10;
    }

    if (original == invertido)
    {
        if (original % 2 == 0)
        {
            printf("%d é Palíndromo e par.\n", original);
        }
        else
        {
            printf("%d é Palíndromo e impar.\n", original);
        }
    }

    else
    {
        printf("%d não é Palíndromo e par.\n", original);
    }

    return 0;
}