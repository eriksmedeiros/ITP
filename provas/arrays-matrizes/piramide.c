#include <stdio.h>

void matriz(int n)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            int min;
            if (i < j)
            {
                min = i;
            }
            else
            {
                min = j;
            }
            if (n - i + 1 < min)
            {
                min = (n - i + 1);
            }

            if (n - j + 1 < min)
            {
                min = (n - j + 1);
            }

            printf("%d ", min);
        }
        printf("\n");
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    matriz(n);

    return 0;
}
