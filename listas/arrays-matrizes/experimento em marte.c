#include <stdio.h>
#include <math.h>

int main()
{
    int N, M, S;
    scanf("%d %d %d", &N, &M, &S);

    int mapa[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &mapa[i][j]);
        }
    }

    int melhorI = 0, melhorJ = 0;
    int diferencaMelhor = S - mapa[0][0];

    for (int i = 0; i <= N - 3; i++)
    {
        for (int j = 0; j <= M - 3; j++)
        {
            int soma = 0;
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    soma += mapa[k][l];
                }
            }
            int diferenca = abs(S - soma);
            if (diferenca < diferencaMelhor)
            {
                melhorI = i;
                melhorJ = j;
                diferencaMelhor = diferenca;
            }
        }
    }

    printf("A melhor area para exploracao eh %d %d com valor %d\n", melhorI + 1, melhorJ + 1, diferencaMelhor);

    return 0;
}