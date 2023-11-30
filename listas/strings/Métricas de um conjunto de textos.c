#include <stdio.h>
#include <string.h>

/*void read_line(char linha[], int tam, FILE *f)
{
    fgets(linha, tam, f);
    while (linha[0] == '\n')
        fgets(linha, tam, f);
    if (linha[strlen(linha) - 1] == '\n')
        linha[strlen(linha) - 1] = '\0';
}*/

void matriz(int numero)
{
    char strings[numero][100];

    for (int i = 0; i < numero; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            fgets(strings[i], 100, stdin);
        }
    }

        int menor_tamanho = strlen(strings[0]);

    for (int i = 1; i < numero; i++)
    {
        int tamanho_atual = strlen(strings[i]);
        if (tamanho_atual < menor_tamanho)
        {
            menor_tamanho = tamanho_atual;
        }
    }

    printf("%d\n", menor_tamanho);
}

int main()
{

    int n;
    scanf("%d", &n);

    matriz(n);

    return 0;
}