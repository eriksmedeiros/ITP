#include <stdio.h>

#define SIZE 10

int main()
{
    char grid[SIZE][SIZE];

    // Inicializar a grade com água
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            grid[i][j] = '~';
        }
    }

    // Ler e colocar a canoa
    int x, y;
    scanf("%d %d", &x, &y);
    grid[x][y] = '*';

    // Ler e colocar o barco de 2 posições
    int x1, y1, x2, y2;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    if (x1 == x2)
    { // horizontal
        if (y1 < y2)
        {
            grid[x1][y1] = '<';
            grid[x2][y2] = '>';
        }
        else
        {
            grid[x1][y1] = '>';
            grid[x2][y2] = '<';
        }
    }
    else
    { // vertical
        if (x1 < x2)
        {
            grid[x1][y1] = '^';
            grid[x2][y2] = 'v';
        }
        else
        {
            grid[x1][y1] = 'v';
            grid[x2][y2] = '^';
        }
    }

    // Ler e colocar a fragata de 3 posições
    int coords[3][2];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &coords[i][0], &coords[i][1]);
    }

    if (coords[0][0] == coords[1][0])
    { // horizontal
        grid[coords[0][0]][coords[0][1]] = '<';
        grid[coords[1][0]][coords[1][1]] = '=';
        grid[coords[2][0]][coords[2][1]] = '>';
    }
    else
    { // vertical
        grid[coords[0][0]][coords[0][1]] = '^';
        grid[coords[1][0]][coords[1][1]] = '|';
        grid[coords[2][0]][coords[2][1]] = 'v';
    }

    // Ler e colocar o destroier de 4 posições
    int x3, y3, x4, y4;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    scanf("%d %d", &x4, &y4);
    if (x1 == x2)
    { // horizontal
        grid[x1][y1] = '<';
        grid[x2][y2] = '=';
        grid[x3][y3] = '=';
        grid[x4][y4] = '>';
    }
    else
    { // vertical
        grid[x1][y1] = '^';
        grid[x2][y2] = '|';
        grid[x3][y3] = '|';
        grid[x4][y4] = 'v';
    }

    // Imprimir a grade
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}