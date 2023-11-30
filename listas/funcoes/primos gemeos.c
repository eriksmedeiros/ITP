#include <stdio.h>
#include <stdbool.h>

int primos(int n)
{
    int divisores = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisores++;
        }
    }

    return (divisores == 2) ? true : false;
}

int primos_gemeos()
{
}

int main()
{
    int n;

    scanf("%d", &n);

    if (primos(n) && primos(n + 2))
    {
        printf("Numero forma par de gemeos\n");
    }
    else
    {
        printf("Numero nao forma par de gemeos\n");
    }
}
