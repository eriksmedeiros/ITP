#include <stdio.h>

int mdc(int x, int y)
{
    if (y == 0)
    {
        printf("MDC(%d, %d) = %d\n", x, y, x);
    }
    else
    {

        while (y != 0)
        {

            int temp = x % y;

            x = y;
            y = temp;
        }
    }
    return x;
}

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);

    printf("MDC(%d , %d) = %d\n", x, y, mdc(x, y));

    return 0;
}
