#include <stdio.h>
#include <stdlib.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted)
{
    int contagem[10] = {0};

    for (int i = 0; i < n; i++)
    {
        contagem[votes[i] - 1]++;
    }

    *most_voted = 0;
    *second_most_voted = 0;

    for (int i = 0; i < 10; i++)
    {
        if (contagem[i] > contagem[*most_voted])
        {
            *second_most_voted = *most_voted;
            *most_voted = i;
        }
        else if (contagem[i] > contagem[*second_most_voted])
        {
            *second_most_voted = i;
        }
    }

    printf("%d ", *most_voted + 1);
    printf("%d\n", *second_most_voted + 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    int vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    int most_voted, second_most_voted;
    compute_votes(n, vet, &most_voted, &second_most_voted);

    return 0;
}