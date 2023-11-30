/*[ITP] Palíndromo de qualquer tamanho

Um palíndromo é texto que, lido em sentido direto ou inverso, permanece o mesmo. Logo, strings​ como "ata", "matam", "omississimo" são palíndromos. Até mesmo frases como "a grama e amarga" e "a torre da derrota" são exemplos de palíndromos, quando removidos os espaços.

******

Desenvolva um programa que, usando recursão, determina se um texto é um palíndromo ou não. O programa deverá:

1) possuir uma função wrapper que recebe como argumento apenas o texto a ser checado; a função deverá ter a seguinte assinatura:

int palindromo(char *entrada);
esta função será responsável por chamar a função recursiva e demais funções do programa, conforme necessário; deverá retornar:

1, se o texto é palíndromo, ou
0, caso contrário;
2) possuir uma função recursiva, que será chamada a partir da função wrapper e irá de determinar se o texto é ou não palíndromo;

3) receber, na função principal, o texto de entrada e usar a função wrapper para avaliá-lo, imprimindo: "O texto "<texto>" é palíndromo", em caso afirmativo, e "O texto "<texto>" não é palíndromo", caso contrário. A entrada poderá ser de qualquer tamanho.

Obs: O programa deve ignorar os espaços dos textos recebidos!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *removeSpace(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (isspace(string[i]))
        {
            for (int j = 0; j < (strlen(string) - i); j++)
                string[i + j] = string[i + j + 1];
        }
    }
    return string;
}

int isPalindromo(char *string, int first, int last)
{
    if (first >= last)
        return 1;
    else if (string[last] != string[first])
        return 0;

    return isPalindromo(string, (first + 1), (last - 1));
}

int palindromo(char *entrada)
{
    char string[200];

    strcpy(string, entrada);
    removeSpace(string);

    return isPalindromo(string, 0, (strlen(string) - 1));
}

int main()
{
    char frase[200];
    scanf(" %[^\n]", frase);

    printf("O texto \"%s\" %s palíndromo\n", frase, (palindromo(frase)) ? "é" : "não é");

    return 0;
}