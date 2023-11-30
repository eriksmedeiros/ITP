/*No intuito de fazer um estudo mais aprofundado em relação aos dados da população mundial, você deseja saber quais os países de baixo IDH possuem uma grande população. Isto é, dado uma relação de países e seus respectivos dados, saber dos que têm IDH abaixo da média, quais os que têm população acima da média. Ao final, seu programa deve ter 3 conjuntos de dados: um com todos os países passados, outro com os países do conjunto anterior que possuem o IDH abaixo da média, e o terceiro com os países do conjunto anterior que possuem a população acima da média.

Para isso, defina inicialmente um tipo estruturado com campos para o acrônimo do país (definido por 3 caracteres), sua população e seu IDH. Defina também uma função para ir adicionando os países lidos em um array. Uma vez que não se sabe à princípio a quantidade de países, o tamanho deste array deve ir se ajustando à medida que dados de novos países são passados para a função.

Escreva também uma função para calcular a média dos dados dos países. Como será necessário calcular tanto a média do IDH quanto a de população, reutilize a mesma função para os dois casos, informando sobre qual informação se deseja trabalhar. Para isso, defina uma enumeração com essa informação.

Seu programa deve ler a relação de países até encontrar "---", como mostra os exemplos de entrada e saída esperadas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pais
{
    char nome[4];
    int populacao;
    float idh;
};

float calcularMedia(struct Pais *paises, int numPaises)
{
    float soma = 0;
    for (int i = 0; i < numPaises; i++)
    {
        soma += paises[i].populacao;
    }
    return soma / numPaises;
}

void imprimirPaises(struct Pais *paises, int numPaises, float mediaPopulacao)
{
    for (int i = 0; i < numPaises; i++)
    {
        if (paises[i].populacao > mediaPopulacao)
        {
            printf("%s\n", paises[i].nome);
        }
    }
}

int main()
{
    struct Pais *paises = NULL;
    int numPaises = 0;
    char nomePais[4];
    int populacao;
    float idh;

    while (1)
    {
        scanf("%s", nomePais);

        if (strcmp(nomePais, "---") == 0)
        {
            break;
        }

        scanf("%d %f", &populacao, &idh);

        paises = (struct Pais *)realloc(paises, (numPaises + 1) * sizeof(struct Pais));

        strcpy(paises[numPaises].nome, nomePais);
        paises[numPaises].populacao = populacao;
        paises[numPaises].idh = idh;

        numPaises++;
    }

    float mediaPopulacao = calcularMedia(paises, numPaises);

    imprimirPaises(paises, numPaises, mediaPopulacao);

    free(paises);

    return 0;
}
