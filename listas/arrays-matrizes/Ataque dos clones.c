#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int x, y;
    scanf("%d %d", &x, &y);

    int mapa[n][m], maior[100][100] = {0};

    // LER O MAPA
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mapa[i][j]);
        }
    }

    // VERIFICA SE HÁ BOMBAS
    int local = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int bomba = 1;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int dx = i + k;
                    int dy = j + l;
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m && (dx != i || dy != j))
                    {
                        if (mapa[dx][dy] >= mapa[i][j])
                        {
                            bomba = 0;
                            break;
                        }
                    }
                }
                if (!bomba)
                {
                    break;
                }
            }
            if (bomba)
            {
                maior[i][j] = 1;
                local++;
                printf("Local %d: %d %d\n", local, i + 1, j + 1);
            }
        }
    }

    // VERIFICA SE ALGUM JEDI FOI ATINGIDO
    if (maior[x - 1][y - 1])
    {
        printf("Descanse na Força...\n");
    }
    else
    {
        printf("Ao resgate!\n");
    }

    return 0;
}
