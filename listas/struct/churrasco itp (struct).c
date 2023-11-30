#include <stdio.h>

typedef struct
{
    char item[40];
    float preco;
    int quantidade;
} tabela;

int main()
{
    tabela churrasco[20];
    int aux = 0, i = 0;

    while (aux != 2)
    {
        scanf("%s", *&churrasco[i].item);
        scanf("%f", &churrasco[i].preco);
        scanf("%d", &churrasco[i].quantidade);
        scanf("%d", &aux);
        i++;
    }

    int pessoas;
    scanf("%d", &pessoas);

    float total = 0;
    for (int j = 0; j < i; j++)
    {
        total += (churrasco[j].preco * churrasco[j].quantidade);
    }

    printf("Valor: R$ %.2f\n", total);
    printf("Divisão R$ %.2f para cada participante.\n", total / pessoas);

    return 0;
}