#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_line(char linha[], int tam, FILE *f)
{
    fgets(linha, tam, f);
    while (linha[0] == '\n')
        fgets(linha, tam, f);
    if (linha[strlen(linha) - 1] == '\n')
        linha[strlen(linha) - 1] = '\0';
}

int tam_Maximo(int numero, char string[numero][100])
{
    int maior_tamanho = strlen(string[0]);

    for (int i = 0; i < numero; i++)
    {

        int posicao = strlen(string[i]);

        if (posicao > maior_tamanho)
        {
            maior_tamanho = posicao;
        }
    }

    return maior_tamanho;
}

int tam_Minimo(int numero, char string[numero][100])
{
    int menor_tamanho = strlen(string[0]);

    for (int i = 0; i < numero; i++)
    {

        int posicao = strlen(string[i]);

        if (posicao < menor_tamanho)
        {
            menor_tamanho = posicao;
        }
    }

    return menor_tamanho;
}

float tam_Medio(int numero, char string[numero][100])
{
    float soma = 0;

    for (int i = 0; i < numero; i++)
    {
        soma += strlen(string[i]);
    }

    return soma / numero;
}

char *mais_proxima(int numero, char string[numero][100])
{

    float media = tam_Medio(numero, string);
    int maisProxima = 0;
    float diferenca = media - strlen(string[0]);
    if (diferenca < 0)
    {
        diferenca = -diferenca;
    }

    for (int i = 1; i < numero; i++)
    {
        float diferencaAtual = media - strlen(string[i]);
        if (diferencaAtual < 0)
        {
            diferencaAtual = -diferencaAtual;
        }
        if (diferencaAtual < diferenca)
        {
            diferenca = diferencaAtual;
            maisProxima = i;
        }
    }

    return string[maisProxima];
}

int tamanhoAtual(char *string)
{
    int tamanho = 0;
    while (string[tamanho] != '\0')
    {
        tamanho++;
    }
    return tamanho;
}

int main()
{
    int n;
    scanf("%d", &n);

    char string[n][100];

    for (int i = 0; i < n; i++)
    {
        read_line(string[i], 100, stdin);
    }

    printf("Tamanho máximo: %d\n", tam_Maximo(n, string));
    printf("Tamanho mínimo: %d\n", tam_Minimo(n, string));
    printf("Tamanho médio: %.2f\n", tam_Medio(n, string));

    char *maisProxima = mais_proxima(n, string);
    printf("Tamanho mais próximo da média %d\n", tamanhoAtual(maisProxima));
    printf("Textos\n%s\n", maisProxima);
    return 0;
}