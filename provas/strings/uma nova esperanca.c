#include <stdio.h>
#include <string.h>

int busca(char mensagem[200], int indices[200], const char S[40])
{
    for (int i = 0; i < 200; i++)
    {

        if (mensagem[i] == '\0' || mensagem[i] == '\n')
        {
            indices[i] = -1;
            return 1;
        }

        int encontrou = 0;
        for (int j = 0; j < 40; j++)
        {
            if (mensagem[i] == S[j])
            {
                indices[i] = j;
                encontrou = 1;
                break;
            }
        }

        if (!encontrou)
        {
            return 0;
        }
    }

    return 1;
}

void codifica(int indices[200], int chave[4], const char S[40], char codificada[200])
{

    int chaveAtual = 0;
    for (int i = 0; i < 200; i++)
    {
        int indice = indices[i];

        if (indice == -1)
        {
            codificada[i] = '\0';
            break;
        }

        int novoIndice = (indice + chave[chaveAtual]) % 40;
        chaveAtual = (chaveAtual + 1) % 4;

        codificada[i] = S[novoIndice];
    }
}

int main()
{
    char mensagem[200], codificada[200];
    int chaves[4];
    const char S[] =
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
         'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
         'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

    char strChaves[7];

    fgets(strChaves, 7, stdin);

    if (strlen(strChaves) > 5)
    {
        printf("Chave invalida\n");
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        chaves[i] = strChaves[i] - '0';
    }

    fflush(stdin);
    fgets(mensagem, 200, stdin);

    int indices[200];

    if (busca(mensagem, indices, S))
    {
        codifica(indices, chaves, S, codificada);
        printf("%s\n", codificada);
    }
    else
    {
        printf("Caractere invalido na entrada\n");
    }

    return 0;
}