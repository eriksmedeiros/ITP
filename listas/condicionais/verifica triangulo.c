#include <stdio.h>

int main()
{

    int lado1, lado2, lado3;

    scanf("%d", &lado1);
    scanf("%d", &lado2);
    scanf("%d", &lado3);

    if (lado1 < lado2 + lado3 && lado2 < lado1 + lado3 && lado3 < lado2 + lado1)
    {
        printf("possivel");
    }
    else
    {
        printf("impossivel");
    }
    return 0;
}