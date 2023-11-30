/* [ITP] Pacman

Um clássico dos arcades, e um dos primeiros grandes sucessos da indústria dos jogos, Pacman, ou o popular "Come-Come", é até hoje jogado por pessoas de várias idades e grupos sociais. O jogo é um desafio de navegação em um labirinto, e o seu objetivo é consumir todas as bolinhas que estão pelo caminho. Porém nem tudo na vida é só comilança, e um grupo de fantasmas percorre o labirinto atrás do herói guloso. Caso um fantasma alcance o Pacman, é Game Over!!

Caso você não conheça o jogo, digita Pacman no Google, e joga no próprio Doodle :)

Mas calma, você não vai implementar o jogo do Pacman...ainda.

A sua tarefa vai ser mais simples: dado um mapa do jogo, você vai avaliar os caminhos e contar quantas bolinhas o Pacman consegue comer no cenário sem ser bloqueado por paredes ou fantasmas. O mapa será representado como uma matriz de caracteres onde:

. - representa uma bolinha

* - representa uma parede

M - representa um fantasma inimigo

C - representa o Pacman.

Seu programa iniciará lendo dois valores inteiros representando o tamanho dessa matriz, em linhas e colunas. Na sequência, a matriz de caracteres é informada.

Para cada cenário, você deve calcular quantas bolinhas foram devoradas, e fazer a impressão do mapa, substituindo as bolinhas devoradas por um espaço vazio.

Por exemplo, para a seguinte entrada:

4 4

**.*

*C.*

*M.*

****

Teríamos como resultado que o Pacman conseguiria comer as três bolinhas, e a matriz final a ser impressa ficaria:

4 4

** *

*C *

*M *

****

Ou seja, todas as bolinhas foram trocadas por espaços em branco. Eu sei, nos casos de teste do LoP os desenhos ficam feios, mas no terminal (ou o replit.com) eles ficam mais bonitinhos como o do texto :P

Observe atentamente os casos de teste para não errar as formatações de entrada e saída.

DICA: use recursão, vai diminuir muito sua dor de cabeça :) */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nrow, ncol;
    char **matriz;
} Mapa;

Mapa *alocMapa(int nrow, int ncol)
{
    static Mapa mapa;
    mapa.ncol = ncol;
    mapa.nrow = nrow;

    mapa.matriz = malloc(sizeof(char *) * nrow);
    for (int i = 0; i < nrow; i++)
        mapa.matriz[i] = malloc(sizeof(char) * nrow);

    return (&mapa);
}

void readMapa(Mapa *mapa)
{
    for (int i = 0; i < mapa->nrow; i++)
    {
        for (int j = 0; j < mapa->ncol; j++)
            scanf(" %c", &mapa->matriz[i][j]);
    }
}

void destroyMapa(Mapa **mapa)
{
    for (int i = 0; i < (*mapa)->nrow; i++)
        free((*mapa)->matriz[i]);
    free((*mapa)->matriz);
    *mapa = NULL;
}

void printMapa(Mapa *mapa)
{
    for (int i = 0; i < mapa->nrow; i++)
    {
        for (int j = 0; j < mapa->ncol; j++)
            printf("%c", mapa->matriz[i][j]);
        puts("");
    }
}

// Localiza o Pacman
int findPacman(Mapa *mapa, int *rowPacman, int *colPacman)
{
    for (int i = 0; i < mapa->nrow; i++)
    {
        for (int j = 0; j < mapa->ncol; j++)
        {
            if (mapa->matriz[i][j] == 'C')
            {
                *rowPacman = i;
                *colPacman = j;

                return 1;
            }
        }
    }

    return 0;
}

// Percorre o mapa a partir do xyPacman até encontrar as bolinhas
int findValidBolinha(Mapa *mapa, int row, int col, int *bolinhas)
{
    // Direita
    if ((row >= 0 && row < mapa->nrow) && ((col + 1) >= 0 && (col + 1) < mapa->ncol))
    {
        if (mapa->matriz[row][col + 1] == '.')
        {
            mapa->matriz[row][col + 1] = ' ';
            (*bolinhas)++;

            if (findValidBolinha(mapa, row, (col + 1), &(*bolinhas)))
                return 1;
        }
    }

    // Esquerda
    if ((row >= 0 && row < mapa->nrow) && ((col - 1) >= 0 && (col - 1) < mapa->ncol))
    {
        if (mapa->matriz[row][col - 1] == '.')
        {
            mapa->matriz[row][col - 1] = ' ';
            (*bolinhas)++;

            if (findValidBolinha(mapa, row, (col - 1), &(*bolinhas)))
                return 1;
        }
    }

    // Cima
    if (((row - 1) >= 0 && (row - 1) < mapa->nrow) && (col >= 0 && col < mapa->ncol))
    {
        if (mapa->matriz[row - 1][col] == '.')
        {
            mapa->matriz[row - 1][col] = ' ';
            (*bolinhas)++;

            if (findValidBolinha(mapa, (row - 1), col, &(*bolinhas)))
                return 1;
        }
    }

    // Baixo
    if (((row + 1) >= 0 && (row + 1) < mapa->nrow) && (col >= 0 && col < mapa->ncol))
    {
        if (mapa->matriz[row + 1][col] == '.')
        {
            mapa->matriz[row + 1][col] = ' ';
            (*bolinhas)++;

            if (findValidBolinha(mapa, (row + 1), col, &(*bolinhas)))
                return 1;
        }
    }

    return 0;
}

int kirbyMode(Mapa *mapa)
{
    int rowPacman, colPacman;
    int bolinhas = 0;

    if (findPacman(mapa, &rowPacman, &colPacman))
    {
        findValidBolinha(mapa, rowPacman, colPacman, &bolinhas);
    }

    return bolinhas;
}

int main()
{
    int nrow, ncol, bolinha = 0;
    scanf("%d %d", &nrow, &ncol);
    Mapa *mapa;

    mapa = alocMapa(nrow, ncol);
    readMapa(mapa);

    bolinha = kirbyMode(mapa);

    printf("Total de bolinhas devoradas: %d \n", bolinha);
    puts("Mapa final:");
    printMapa(mapa);

    destroyMapa(&mapa);

    return 0;
}