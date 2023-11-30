#include <stdio.h>

int jogadas(char mapa[3][3], char simb)
{
    for (int i = 0; i < 3; i++)
    {
        if (mapa[i][0] == simb && mapa[i][1] == simb && mapa[i][2] == simb)
        {
            return 1;
        }
        if (mapa[0][i] == simb && mapa[1][i] == simb && mapa[2][i] == simb)
        {
            return 1;
        }
    }
    if (mapa[0][0] == simb && mapa[1][1] == simb && mapa[2][2] == simb)
    {
        return 1;
    }
    if (mapa[0][2] == simb && mapa[1][1] == simb && mapa[2][0] == simb)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int i, j;

    char mapa[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf(" %c", &mapa[i][j]);
        }
    }

    int N;
    scanf("%d", &N);

    int x, y;
    char simb;

    for (i = 0; i < N; i++)
    {

        scanf("%d %d %c", &x, &y, &simb);

        x--;
        y--;

        if (mapa[x][y] == 'X' || mapa[x][y] == 'O')
        {
            printf("Jogada inválida!\n");
        }
        else
        {
            mapa[x][y] = simb;
            if (jogadas(mapa, simb))
            {
                printf("Boa jogada, vai vencer!\n");
                mapa[x][y] = '.';
            }
            else
            {
                printf("Continua o jogo.\n");
                mapa[x][y] = '.';
            }
        }
    }

    return 0;
}