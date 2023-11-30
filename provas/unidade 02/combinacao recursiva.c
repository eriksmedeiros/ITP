/*escreva uma função recursiva para calcular a combinação de N elementos de P em P. Preste atenção em todos os possíveis casos-base. Ou seja, veja quais os casos em que a quantidade de combinações é obrigatoriamente 0 ou 1, sem precisar chamar recursivamente a mesma função.

Escreva um programa que lê da entrada-padrão dois valores inteiros, correspondendo respectivamente ao N e P citado, e envia para a saída-padrão o valor de CpnC^n_pCpn​​. Use a função recursiva para esse propósito.*/
#include <stdio.h>

// Função para calcular combinação C^n_p
int combinacao(int n, int p)
{
    // Caso-base 1: Cn0 = 1 para qualquer n
    if (p == 0)
    {
        return 1;
    }
    // Caso-base 2: Cnn = 1 para qualquer n
    else if (n == p)
    {
        return 1;
    }
    // Caso recursivo: C^{n}_{p} = C^{n-1}_{p-1} + C^{n-1}_{p}
    else
    {
        return combinacao(n - 1, p - 1) + combinacao(n - 1, p);
    }
}

int main()
{
    int n, p;

    // Lê N e P da entrada-padrão
    scanf("%d", &n);

    scanf("%d", &p);

    // Calcula a combinação C^{n}_{p} usando a função recursiva
    int resultado = combinacao(n, p);

    // Imprime o resultado na saída-padrão
    printf("%d\n", resultado);

    return 0;
}
